////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//   strncspn() returns the index of the first delimiter in a string.         //
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

// Returns the index of the first delimiter in a string.
unsigned long strncspn(const char string[], unsigned long string_length, const char * delimiters, unsigned long delimiter_count) {
    int i = 0;
    for (; i < string_length; i++) {
        for (int j = 0; j < delimiter_count; j++) {
            if (string[i] == delimiters[j]) {
                return i;
            };
        };
    };
    return -1;
}
