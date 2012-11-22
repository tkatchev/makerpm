#ifndef __PROPSPARSER_H
#define __PROPSPARSER_H

// This file needs to be preprocessed with the 'ragel' tool.
// Run it like this:
//
//   ragel -G2 configparser.rl -o configparser.h
//

#include <string>
#include <stdexcept>
#include <iostream>

#include <string.h>
#include <stdio.h>

#include "rpmprops.h"

namespace propsparser {

struct ragel_state {

    /** Ragel scanner cruft. **/

    // Iterators for start and end of buffer data.
    char* p;
    char* pe;

    // Iterator for 'end of file'.
    char* eof;

    // Iterator for start and end of token.
    char* ts;
    char* te;

    // Internal state and rollback variables.
    int cs, act;

    // Stack for ragel machine states.
    int stack[32];
    int top;

    // Not part of ragel's variables; this is a buffer to hold the current match.
    std::string match;
};


void parse_props(const std::string& filename, rpmprops_t& props) {

    /** File reading cruft. **/

    char buf[4096];

    FILE* fn = ::fopen(filename.c_str(), "r");

    if (fn == NULL) {
        throw std::runtime_error("Could not open: \"" + filename + "\"");
    }

    ragel_state state;

    %%{

        machine PropsParser;

        access state.;
        variable p state.p;
        variable pe state.pe;
        variable eof state.eof;

        action start {
            state.match.clear();
        }

        action push {
            state.match += fc;
        }

        onews = [ \t\r\n];
        ws = onews*;
        ws1 = onews+;
        sep = '_' | ws;

        number = [0-9]+ 
            >start $push;

        snumber = ('-'? [0-9]+)
            >start $push;

        real = (('-'?) (([0-9]+ '\.' [0-9]+) | ([0-9]+)))
            >start $push;

        tag = [a-zA-Z0-9_]+ 
            >start $push;

        #/* 34 is the double quote character, the only reason for writing it like this is to make Emacs happy */
        quote = 34;

        strchar_escape := 
            ( ('"'   ${ state.match += '"';  fret; }) |
              ('n'   ${ state.match += '\n'; fret; }) |
              ('\\'  ${ state.match += '\\'; fret; }) )
            ;

        strchar = ( (^ (quote | '\\') $push ) |
                    ('\\'             ${fcall strchar_escape;} ) );

        strdata = strchar*;

        string = '"' >start strdata '"';

        ###

        locale = [Ll] 'ocale' ':'? (ws1 string %{ props.locale.push_back(state.match); })+;

        name        = [Nn] 'ame' ':'?             ws1 string %{ props.name = state.match; };
        version     = [Vv] 'ersion' ':'?          ws1 string %{ props.version = state.match; };
        release     = [Rr] 'elease' ':'?          ws1 string %{ props.release = state.match; };
        summary     = [Ss] 'ummary' ':'?          ws1 string %{ props.summary = state.match; };
        description = [Dd] 'escription' ':'?      ws1 string %{ props.description = state.match; };
        buildhost   = [Bb] 'uild' [Hh] 'ost' ':'? ws1 string %{ props.buildhost = state.match; };
        license     = [Ll] 'icense' ':'?          ws1 string %{ props.license = state.match; };
        packager    = [Pp] 'ackager' ':'?         ws1 string %{ props.packager = state.match; };
        group       = [Gg] 'roup' ':'?            ws1 string %{ props.group = state.match; };
        url         = [Uu] [Rr] [Ll] ':'?         ws1 string %{ props.url = state.match; };
        os          = [Oo] [Ss] ':'?              ws1 string %{ props.os = state.match; };
        arch        = [Aa] 'rch' ':'?             ws1 string %{ props.arch = state.match; };
        platform    = [Pp] 'latform' ':'?         ws1 string %{ props.platform = state.match; };
        optflags    = [Oo] 'pt' [Ff] 'lags' ':'?  ws1 string %{ props.optflags = state.match; };

        rpmversion  = [Rr] [Pp] [Mm] [Vv] 'ersion' ':'? ws1 string %{ props.rpmversion = state.match; };

        prein = [Pp] 're' [Ii] 'n' ':'? ws1 
            ('shell' ws1 string %{ props.prein.prog = state.match; } ws1)?
            string %{ props.prein.code = state.match; };

        postin = [Pp] 'ost' [Ii] 'n' ':'? ws1 
            ('shell' ws1 string %{ props.postin.prog = state.match; } ws1)?
            string %{ props.postin.code = state.match; };

        preun = [Pp] 're' [Uu] 'n' ':'? ws1 
            ('shell' ws1 string %{ props.preun.prog = state.match; } ws1)?
            string %{ props.preun.code = state.match; };

        postun = [Pp] 'ost' [Uu] 'n' ':'? ws1 
            ('shell' ws1 string %{ props.postun.prog = state.match; } ws1)?
            string %{ props.postun.code = state.match; };

        entry = 
            locale | name | version | release | summary | description | buildhost | license |
            packager | group | url | os | arch | platform | optflags | rpmversion |
            prein | postin | preun | postun 
            ;
            
      main := (ws entry)+ ws ;
        
    }%%
/*

*/

    %% write data;
    %% write init;

    bool done = false;
    int have = 0;

    while (!done) {
        int space = sizeof(buf) - have;
        if (space == 0) {
            throw std::runtime_error("Token too big!");
        }

        state.p = buf + have;
        int len = ::fread(state.p, 1, space, fn);
        
        state.pe = state.p + len;
        state.eof = 0;
        
        if (len == 0) {
            state.eof = state.pe;
            done = true;
        }

        %% write exec;

        // Avoid spurious gcc warnings.

        if (state.cs == PropsParser_error) {
            throw std::runtime_error("Parse error. Unconsumed input: " + std::string(state.p, state.pe));
        }

        if (state.ts == 0) {
            have = 0;

        } else {
            have = state.pe - state.ts;
            ::memmove(buf, state.ts, have);
            state.te = buf + (state.te - state.ts);
            state.ts = buf;
        }
    }
}

}

#endif
