////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//   strncmp() returns the difference of the first deviant chars of a and b.  //
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

// Returns the difference between the first differing characters between two strings, or 0 if they are equal.
char strncmp(const char string_a[], const char string_b[], unsigned long length) {
    for (int i = 0; (((char *) string_a)[i] != 0) & (((char *) string_b)[i] != 0) & (i < length); i++) {
        if (((char *) string_a)[i] != ((char *) string_b)[i]) {
            return ((char *) string_a)[i] - ((char *) string_b)[i];
        };
    };
    return 0;
};
