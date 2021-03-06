#ifndef __MAKERPM_RPMTAGS_H
#define __MAKERPM_RPMTAGS_H

namespace rpm {


enum TAGS {

    TAG_HEADERSIGNATURES = 62,
    TAG_SHA1HEADER = 269,
    TAG_SIGSIZE = 1000,
    TAG_SIGLONGSIZE = 270,
    TAG_MD5 = 1004,
    TAG_PAYLOADSIZE = 1007,
    TAG_PAYLOADLONGSIZE = 271,

    TAG_HEADERIMMUTABLE = 63,
    TAG_HEADERI18NTABLE = 100,

    TAG_NAME = 1000,
    TAG_VERSION = 1001,
    TAG_RELEASE = 1002, 
    TAG_SUMMARY = 1004,
    TAG_DESCRIPTION = 1005,
    TAG_BUILDTIME = 1006,
    TAG_BUILDHOST = 1007,
    TAG_SIZE = 1009,
    
    TAG_LICENSE = 1014,
    TAG_PACKAGER = 1015,
    TAG_GROUP = 1016,

    TAG_URL = 1020,
    TAG_OS = 1021,
    TAG_ARCH = 1022,
    TAG_PREIN = 1023,
    TAG_POSTIN = 1024,
    TAG_PREUN = 1025,
    TAG_POSTUN = 1026,

    TAG_FILESIZES = 1028,
    TAG_FILEMODES = 1030,

    TAG_FILERDEVS = 1033,
    TAG_FILEMTIMES = 1034,
    TAG_FILEDIGESTS = 1035,
    TAG_FILELINKTOS = 1036,
    TAG_FILEFLAGS = 1037,

    TAG_FILEUSERNAME = 1039,
    TAG_FILEGROUPNAME = 1040,

    TAG_SOURCERPM = 1044,
    TAG_FILEVERIFYFLAGS = 1045,
    TAG_PROVIDENAME = 1047,
    TAG_REQUIREFLAGS = 1048,
    TAG_REQUIRENAME = 1049,
    TAG_REQUIREVERSION = 1050,

    TAG_CONFLICTFLAGS = 1053,
    TAG_CONFLICTNAME = 1054,
    TAG_CONFLICTVERSION = 1055,

    TAG_RPMVERSION = 1064,

    TAG_CHANGELOGTIME = 1080,
    TAG_CHANGELOGNAME = 1081,
    TAG_CHANGELOGTEXT = 1082,

    TAG_PREINPROG = 1085,
    TAG_POSTINPROG = 1086,
    TAG_PREUNPROG = 1087,
    TAG_POSTUNPROG = 1088,

    TAG_OBSOLETENAME = 1090,

    TAG_FILEDEVICES = 1095,
    TAG_FILEINODES = 1096,
    TAG_FILELANGS = 1097,

    TAG_SOURCEPACKAGE = 1106,

    TAG_PROVIDEFLAGS = 1112,
    TAG_PROVIDEVERSION = 1113,

    TAG_OBSOLETEFLAGS = 1114,
    TAG_OBSOLETEVERSION = 1115,

    TAG_DIRINDEXES = 1116,
    TAG_BASENAMES = 1117,
    TAG_DIRNAMES = 1118,

    TAG_OPTFLAGS = 1122,

    TAG_PAYLOADFORMAT = 1124,
    TAG_PAYLOADCOMPRESSOR = 1125,
    TAG_PAYLOADFLAGS = 1126,

    TAG_RHNPLATFORM = 1131,
    TAG_PLATFORM = 1132,

    TAG_FILECOLORS = 1140,
    TAG_FILECLASS = 1141,
    TAG_CLASSDICT = 1142,
    TAG_FILEDEPENDSX = 1143,
    TAG_FILEDEPENDSN = 1144,
    
    TAG_FILECONTEXTS = 1147,

    TAG_LONGFILESIZES = 5008,
    TAG_LONGSIZE = 5009

};

std::string tag_printable(unsigned int tag) {

    switch (tag) {
    case TAG_HEADERSIGNATURES: return "HEADERSIGNATURES";
    case TAG_SHA1HEADER: return "SHA1HEADER";
    case TAG_SIGSIZE: return "SIGSIZE or NAME";
    case TAG_SIGLONGSIZE: return "SIGLONGSIZE";
    case TAG_MD5: return "MD5 or SUMMARY";
    case TAG_PAYLOADSIZE: return "PAYLOADSIZE or BUILDHOST";
    case TAG_PAYLOADLONGSIZE: return "PAYLOADLONGSIZE";
    case TAG_HEADERIMMUTABLE: return "HEADERIMMUTABLE";
    case TAG_HEADERI18NTABLE: return "HEADERI18NTABLE";
    case TAG_VERSION: return "VERSION";
    case TAG_RELEASE: return "RELEASE"; 
    case TAG_DESCRIPTION: return "DESCRIPTION";
    case TAG_BUILDTIME: return "BUILDTIME";
    case TAG_SIZE: return "SIZE";
    case TAG_LICENSE: return "LICENSE";
    case TAG_PACKAGER: return "PACKAGER";
    case TAG_GROUP: return "GROUP";
    case TAG_URL: return "URL";
    case TAG_OS: return "OS";
    case TAG_ARCH: return "ARCH";
    case TAG_PREIN: return "PREIN";
    case TAG_POSTIN: return "POSTIN";
    case TAG_PREUN: return "PREUN";
    case TAG_POSTUN: return "POSTUN";
    case TAG_FILESIZES: return "FILESIZES";
    case TAG_FILEMODES: return "FILEMODES";
    case TAG_FILERDEVS: return "FILERDEVS";
    case TAG_FILEMTIMES: return "FILEMTIMES";
    case TAG_FILEDIGESTS: return "FILEDIGESTS";
    case TAG_FILELINKTOS: return "FILELINKTOS";
    case TAG_FILEFLAGS: return "FILEFLAGS";
    case TAG_FILEUSERNAME: return "FILEUSERNAME";
    case TAG_FILEGROUPNAME: return "FILEGROUPNAME";
    case TAG_SOURCERPM: return "SOURCERPM";
    case TAG_FILEVERIFYFLAGS: return "FILEVERIFYFLAGS";
    case TAG_PROVIDENAME: return "PROVIDENAME";
    case TAG_REQUIREFLAGS: return "REQUIREFLAGS";
    case TAG_REQUIRENAME: return "REQUIRENAME";
    case TAG_REQUIREVERSION: return "REQUIREVERSION";
    case TAG_CONFLICTFLAGS: return "CONFLICTFLAGS";
    case TAG_CONFLICTNAME: return "CONFLICTNAME";
    case TAG_CONFLICTVERSION: return "CONFLICTVERSION";
    case TAG_RPMVERSION: return "RPMVERSION";
    case TAG_CHANGELOGTIME: return "CHANGELOGTIME";
    case TAG_CHANGELOGNAME: return "CHANGELOGNAME";
    case TAG_CHANGELOGTEXT: return "CHANGELOGTEXT";
    case TAG_PREINPROG: return "PREINPROG";
    case TAG_POSTINPROG: return "POSTINPROG";
    case TAG_PREUNPROG: return "PREUNPROG";
    case TAG_POSTUNPROG: return "POSTUNPROG";
    case TAG_OBSOLETENAME: return "OBSOLETENAME";
    case TAG_FILEDEVICES: return "FILEDEVICES";
    case TAG_FILEINODES: return "FILEINODES";
    case TAG_FILELANGS: return "FILELANGS";
    case TAG_SOURCEPACKAGE: return "SOURCEPACKAGE";
    case TAG_PROVIDEFLAGS: return "PROVIDEFLAGS";
    case TAG_PROVIDEVERSION: return "PROVIDEVERSION";
    case TAG_OBSOLETEFLAGS: return "OBSOLETEFLAGS";
    case TAG_OBSOLETEVERSION: return "OBSOLETEVERSION";
    case TAG_DIRINDEXES: return "DIRINDEXES";
    case TAG_BASENAMES: return "BASENAMES";
    case TAG_DIRNAMES: return "DIRNAMES";
    case TAG_OPTFLAGS: return "OPTFLAGS";
    case TAG_PAYLOADFORMAT: return "PAYLOADFORMAT";
    case TAG_PAYLOADCOMPRESSOR: return "PAYLOADCOMPRESSOR";
    case TAG_PAYLOADFLAGS: return "PAYLOADFLAGS";
    case TAG_RHNPLATFORM: return "RHNPLATFORM";
    case TAG_PLATFORM: return "PLATFORM";
    case TAG_FILECOLORS: return "FILECOLORS";
    case TAG_FILECLASS: return "FILECLASS";
    case TAG_CLASSDICT: return "CLASSDICT";
    case TAG_FILEDEPENDSX: return "FILEDEPENDSX";
    case TAG_FILEDEPENDSN: return "FILEDEPENDSN";
    case TAG_FILECONTEXTS: return "FILECONTEXTS";
    case TAG_LONGFILESIZES: return "LONGFILESIZES";
    case TAG_LONGSIZE: return "LONGSIZE";
    }

    return "";
}

}

#endif
