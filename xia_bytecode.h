////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Copyright (C) 2025 Tanika Claire Mellifont-Young                          //
//  Permission is hereby granted, free of charge, to any person obtaining a   //
//  copy of this software and associated documentation files                  //
//  (the “Software”), to deal in the Software without restriction, including  //
//  without limitation the rights to use, copy, modify, merge, publish,       //
//  distribute, sublicense, and/or sell copies of the Software, and to        //
//  permit persons to whom the Software is furnished to do so, subject to     //
//  the following conditions:                                                 //
//  The above copyright notice and this permission notice shall be included   //
//  in all copies or substantial portions of the Software.                    //
//  THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS   //
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                //
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.    //
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY      //
//  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,      //
//  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE         //
//  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                    //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

// c -> char
// s -> short
// i -> int
// l -> long
// p -> file
// n -> range from stack
// r -> range from code
enum xia_bytecode {
    ERROR = 0,
    HALTX,
    /* io */
    OPENP, // pop char array, open file, push file descriptor
    CLOSP, // pop file descriptor, close file
    READP, // pop file descriptor, array, and size, read size bytes from file descriptor into array, push # of bytes read
    WRITP, //
    NEWXP,
    DELXP,
    BINDP,
    SRVXP,
    RSTTP,
    WSTTP,
    /* stack manipulation */
    PSHXC, // push and jump over char immediately after this opcode
    PSHXS, // push and jump over short immediately after this opcode
    PSHXI, // push and jump over int immediately after this opcode
    PSHXL, // push and jump over long immediately after this opcode
    PSHXR, // push and jump over <code_arg0>(long) bytes immediately after <arg0>
    POPXC, // pop char from stack
    POPXS, // pop short from stack
    POPXI, // pop int from stack
    POPXL, // pop long from stack
    POPXN, // pop <arg0>(long) bytes, not including <arg0>.
    POPXR, // pop <code_arg0>(long) bytes, not including <code_arg0>.
    /* frame manipulation */
    PSHFP, // push frame pointer
    PSHSP, // push stack pointer
    PSHCP, // push code pointer
    POPFP, // pop to frame pointer
    POPSP, // pop to stack pointer
    POPCP, // pop to code pointer
    DLOCC, // dereference local character
    DLOCS, // dereference local short
    DLOCI, // dereference local int
    DLOCL, // dereference local long
    SLOCC, // set local char
    SLOCS, // set local short
    SLOCI, // set local int
    SLOCL, // set local long
    /* pointer manipulation */
    DREFC, // dereference char
    DREFS, // dereference short
    DREFI, // dereference int
    DREFL, // dereference long
    DREFN, // dereference range
    SETXC, // set character pointer
    SETXS, // set short pointer to value
    SETXI, // set int pointer to value
    SETXL, // set long pointer to value
    SETXN, // set range to range from stack
    SETXR, // set range to range from code
    ALLOC, // get pointer to region of size <arg1>
    FREEX, // free region using pointer returned from alloc
    /* control manipulation */
    BRCCN, // jump to <arg1>(code pointer) if <arg2>(char) is not 0
    BRCSN, // jump to <arg1>(code pointer) if <arg2>(short) is not 0
    BRCIN, // jump to <arg1>(code pointer) if <arg2>(int) is not 0
    BRCLN, // jump to <arg1>(code pointer) if <arg2>(long) is not 0
    BRCCZ, // jump to <arg1>(code pointer) if <arg2>(char) is not 0
    BRCSZ, // jump to <arg1>(code pointer) if <arg2>(short) is not 0
    BRCIZ, // jump to <arg1>(code pointer) if <arg2>(int) is not 0
    BRCLZ, // jump to <arg1>(code pointer) if <arg2>(long) is not 0
    /* type manipulation */
    CSTCS, // cast char to short
    CSTCI, // cast char to int
    CSTCL, // cast char to long
    CSTSC, // cast short to char
    CSTSI, // cast short to int
    CSTSL, // cast short to long
    CSTIC, // cast int to char
    CSTIS, // cast int to short
    CSTIL, // cast int to long
    CSTLC, // cast long to char
    CSTLS, // cast long to short
    CSTLI, // cast long to int
    CSTI, // cast char to int
    /* char arithmetic */
    LANDC,
    LORXC,
    LNOTC,
    LXORC,
    BANDC,
    BORXC,
    BNOTC,
    BXORC,
    TEQXC,
    TNQXC,
    TLTXC,
    TGTXC,
    TLEQC,
    TGEQC,
    ASHLC,
    ASHRC,
    ADDXC,
    SUBXC,
    MULXC,
    DIVXC,
    MODXC,
    /* short arithmetic */
    LANDS,
    LORXS,
    LNOTS,
    LXORS,
    BANDS,
    BORXS,
    BNOTS,
    BXORS,
    TEQXS,
    TNQXS,
    TLTXS,
    TGTXS,
    TLEQS,
    TGEQS,
    ASHLS,
    ASHRS,
    ADDXS,
    SUBXS,
    MULXS,
    DIVXS,
    MODXS,
    /* int arithmetic */
    LANDI,
    LORXI,
    LNOTI,
    LXORI,
    BANDI,
    BORXI,
    BNOTI,
    BXORI,
    TEQXI,
    TNQXI,
    TLTXI,
    TGTXI,
    TLEQI,
    TGEQI,
    ASHLI,
    ASHRI,
    ADDXI,
    SUBXI,
    MULXI,
    DIVXI,
    MODXI,
    /* long arithmetic */
    LANDL,
    LORXL,
    LNOTL,
    LXORL,
    BANDL,
    BORXL,
    BNOTL,
    BXORL,
    TEQXL,
    TNQXL,
    TLTXL,
    TGTXL,
    TLEQL,
    TGEQL,
    ASHLL,
    ASHRL,
    ADDXL,
    SUBXL,
    MULXL,
    DIVXL,
    MODXL,
};
const char * xia_bytecode_str[] = {
    [ERROR] = "ERROR",
    [HALTX] = "HALTX",
    /* io */
    [OPENP] = "OPENP",
    [CLOSP] = "CLOSP",
    [READP] = "READP",
    [WRITP] = "WRITP",
    [NEWXP] = "NEWXP",
    [DELXP] = "DELXP",
    [BINDP] = "BINDP",
    [SRVXP] = "SRVXP",
    [RSTTP] = "RSTTP",
    [WSTTP] = "WSTTP",
    /* stack manipulation */
    [PSHXC] = "PSHXC",
    [PSHXS] = "PSHXS",
    [PSHXI] = "PSHXI",
    [PSHXL] = "PSHXL",
    [PSHXR] = "PSHXR",
    [POPXC] = "POPXC",
    [POPXS] = "POPXS",
    [POPXI] = "POPXI",
    [POPXL] = "POPXL",
    [POPXN] = "POPXN",
    [POPXR] = "POPXR",
    /* frame manipulation */
    [PSHFP] = "PSHFP",
    [PSHSP] = "PSHSP",
    [PSHCP] = "PSHCP",
    [POPFP] = "POPFP",
    [POPSP] = "POPSP",
    [POPCP] = "POPCP",
    [DLOCC] = "DLOCC",
    [DLOCS] = "DLOCS",
    [DLOCI] = "DLOCI",
    [DLOCL] = "DLOCL",
    [SLOCC] = "SLOCC",
    [SLOCS] = "SLOCS",
    [SLOCI] = "SLOCI",
    [SLOCL] = "SLOCL",
    /* pointer manipulation */
    [DREFC] = "DREFC",
    [DREFS] = "DREFS",
    [DREFI] = "DREFI",
    [DREFL] = "DREFL",
    [DREFN] = "DREFN",
    [SETXC] = "SETXC",
    [SETXS] = "SETXS",
    [SETXI] = "SETXI",
    [SETXL] = "SETXL",
    [SETXN] = "SETXN",
    [SETXR] = "SETXR",
    [ALLOC] = "ALLOC",
    [FREEX] = "FREEX",
    /* control manipulation */
    [BRCCN] = "BRCCN",
    [BRCSN] = "BRCSN",
    [BRCIN] = "BRCIN",
    [BRCLN] = "BRCLN",
    [BRCCZ] = "BRCCZ",
    [BRCSZ] = "BRCSZ",
    [BRCIZ] = "BRCIZ",
    [BRCLZ] = "BRCLZ",
    /* type manipulation */
    [CSTCS] = "CSTCS",
    [CSTCI] = "CSTCI",
    [CSTCL] = "CSTCL",
    [CSTSC] = "CSTSC",
    [CSTSI] = "CSTSI",
    [CSTSL] = "CSTSL",
    [CSTIC] = "CSTIC",
    [CSTIS] = "CSTIS",
    [CSTIL] = "CSTIL",
    [CSTLC] = "CSTLC",
    [CSTLS] = "CSTLS",
    [CSTLI] = "CSTLI",
    [CSTI] = "CSTI",
    /* char arithmetic */
    [LANDC] = "LANDC",
    [LORXC] = "LORXC",
    [LNOTC] = "LNOTC",
    [LXORC] = "LXORC",
    [BANDC] = "BANDC",
    [BORXC] = "BORXC",
    [BNOTC] = "BNOTC",
    [BXORC] = "BXORC",
    [TEQXC] = "TEQXC",
    [TNQXC] = "TNQXC",
    [TLTXC] = "TLTXC",
    [TGTXC] = "TGTXC",
    [TLEQC] = "TLEQC",
    [TGEQC] = "TGEQC",
    [ASHLC] = "ASHLC",
    [ASHRC] = "ASHRC",
    [ADDXC] = "ADDXC",
    [SUBXC] = "SUBXC",
    [MULXC] = "MULXC",
    [DIVXC] = "DIVXC",
    [MODXC] = "MODXC",
    /* short arithmetic */
    [LANDS] = "LANDS",
    [LORXS] = "LORXS",
    [LNOTS] = "LNOTS",
    [LXORS] = "LXORS",
    [BANDS] = "BANDS",
    [BORXS] = "BORXS",
    [BNOTS] = "BNOTS",
    [BXORS] = "BXORS",
    [TEQXS] = "TEQXS",
    [TNQXS] = "TNQXS",
    [TLTXS] = "TLTXS",
    [TGTXS] = "TGTXS",
    [TLEQS] = "TLEQS",
    [TGEQS] = "TGEQS",
    [ASHLS] = "ASHLS",
    [ASHRS] = "ASHRS",
    [ADDXS] = "ADDXS",
    [SUBXS] = "SUBXS",
    [MULXS] = "MULXS",
    [DIVXS] = "DIVXS",
    [MODXS] = "MODXS",
    /* int arithmetic */
    [LANDI] = "LANDI",
    [LORXI] = "LORXI",
    [LNOTI] = "LNOTI",
    [LXORI] = "LXORI",
    [BANDI] = "BANDI",
    [BORXI] = "BORXI",
    [BNOTI] = "BNOTI",
    [BXORI] = "BXORI",
    [TEQXI] = "TEQXI",
    [TNQXI] = "TNQXI",
    [TLTXI] = "TLTXI",
    [TGTXI] = "TGTXI",
    [TLEQI] = "TLEQI",
    [TGEQI] = "TGEQI",
    [ASHLI] = "ASHLI",
    [ASHRI] = "ASHRI",
    [ADDXI] = "ADDXI",
    [SUBXI] = "SUBXI",
    [MULXI] = "MULXI",
    [DIVXI] = "DIVXI",
    [MODXI] = "MODXI",
    /* long arithmetic */
    [LANDL] = "LANDL",
    [LORXL] = "LORXL",
    [LNOTL] = "LNOTL",
    [LXORL] = "LXORL",
    [BANDL] = "BANDL",
    [BORXL] = "BORXL",
    [BNOTL] = "BNOTL",
    [BXORL] = "BXORL",
    [TEQXL] = "TEQXL",
    [TNQXL] = "TNQXL",
    [TLTXL] = "TLTXL",
    [TGTXL] = "TGTXL",
    [TLEQL] = "TLEQL",
    [TGEQL] = "TGEQL",
    [ASHLL] = "ASHLL",
    [ASHRL] = "ASHRL",
    [ADDXL] = "ADDXL",
    [SUBXL] = "SUBXL",
    [MULXL] = "MULXL",
    [DIVXL] = "DIVXL",
    [MODXL] = "MODXL",
};
