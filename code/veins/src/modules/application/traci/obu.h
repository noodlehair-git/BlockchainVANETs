//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef OBU_H_
#define OBU_H_
#define Nb 4
#define Multiply(x,y) (((y & 1) * x) ^ ((y>>1 & 1) * xtime(x)) ^ ((y>>2 & 1) * xtime(xtime(x))) ^ ((y>>3 & 1) * xtime(xtime(xtime(x)))) ^ ((y>>4 & 1) * xtime(xtime(xtime(xtime(x))))))
class obu {
public:
    obu();
    virtual ~obu();
    void die_with_error(char *errorMessage);
       void die_with_wserror(char *errorMessage);

       unsigned char in[16], out[16], state[4][4];
       unsigned char RoundKey[240];
       unsigned char Key[32];

       int getSBoxValue(int num);
       void KeyExpansion(int Nk,int Nr);
       void AddRoundKey(int round);
       void SubBytes(void);
       void ShiftRows(void);
       void MixColumns(void);
       void Cipher(int Nr);
       void InvCipher();
       void InvMixColumns();
       void InvShiftRows();
       void InvSubBytes();
       void DSAVerification(int val);
       int parseInt(const char *c, int *dst);
       int getSBoxInvert(int num);
};

#endif /* OBU_H_ */
