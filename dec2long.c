////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//   dec2long() parses a string to a long, returning a success boolean.       //
//   Copyright (C) 2025 Tanika Claire Mellifont-Young                         //
//                                                                            //
//   This program is free software: you can redistribute it and/or modify     //
//   it under the terms of the GNU General Public License as published by     //
//   the Free Software Foundation, either version 3 of the License, or        //
//   (at your option) any later version.                                      //
//                                                                            //
//   This program is distributed in the hope that it will be useful,          //
//   but WITHOUT ANY WARRANTY; without even the implied warranty of           //
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
//   GNU General Public License for more details.                             //
//                                                                            //
//   You should have received a copy of the GNU General Public License        //
//   along with this program.  If not, see <https://www.gnu.org/licenses/>.   //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

int dec2long(const char string[], unsigned long length, long * destination) {
    int i = 0;
    long sign = 1;
    switch (string[0]) {
        case '+': {
            i = 1;
        } break;
        case '-': {
            sign = -1;
            i = 1;
        } break;
    };
    for (; i < length; i++) {
        if ((string[i] >= '0') && (string[i] <= '9')) {
            * destination = * destination * 10 + string[i] - '0';
        } else {
            return 0;
        };
    };
    return 1;
};
