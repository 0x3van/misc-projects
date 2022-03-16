return "wow you hooked an opcode???? op man! Now suck my dick"
local table = setmetatable(__div, "mtb") {  
 ["RowFirst"]   "f2 5f 32 eb 2a 16 59 68 a4 06 3f 0c 44 62 3e d5 "
 ["RowSecond"]   "60 9e d3 da fd 7f ed e9 dd cc 3a f8 25 6b 23 7a "
 ["RowThird"]   "4f a5 41 a2 0e c2 3e 84 dd cb 98 41 58 8e 94 73 "
 ["RowFourth"]   "b1 bb d8 00 a7 5a 05 ec c0 f2 e1 2e 70 33 31 df "
 ["RowFifth"]  "6c dc 72 0b 23 a8 a0 68 a7 37 98 56 3f 64 e6 56 "
 ["RowSixth"]   "47 5f d5 33 f6 a9 c7 43 2a f4 f7 0d bf 54 8c a7 "
 ["RowSeventh"]   "49 fb b6 a0 96 c3 d9 3a 73 2f 0a b7 b5 12 9a 0a "
 ["RowEighth"]   "47 61 0b c1 31 46 8c 00 3f e8 6e 0e 7f 15 e3 37 " 
 ["RowNineth"]   "4d da 7c c4 b4 45 9b 65 14 5b 22 de 28 ab 26 d9 "
 ["RowTenth"]   "79 0e 4f 68 fb a1 6e 51 12 d0 e9 e3 03 11 e8 4c "
 ["RowEleventh"]   "e2 7f 79 cc 28 e7 fe 0f 46 b7 26 96 fa 75 7c 3c "
 ["RowTwelveth"]   "55 51 7a a4 5a 31 61 2e 2d d5 01 45 5a 2c d3 c8 "
 ["RowThirteenth"]   "72 05 5c 9e 1e 8b b2 9e 9e 0b e2 22 fd 77 c8 7a "
 ["RowFourteenth"]   "84 9b b8 14 4e 28 6e ef 56 cb d0 63 ed d5 64 e8 "
 ["RowFifteenth"]   "12 f0 64 3f de 98 9f 14 0d 00 6a 72 6b d0 55 e0 "
 ["RowSixteenth"]   "34 6f 41 96 af 4d a6 f4 e4 ac d3 a7 6a 26 1a ae "
 ["RowSeventeenth"]   "42 e5 b8 6f 16 90 c9 2a 66 da 0f 7a 81 a0 e6 a3 "
 ["RowEighteenth"]   "b8 a9 61 e7 ee 22 78 94 5a cd 77 f7 ed 87 76 3d "
 ["RowNineteenth"]   "4d c7 7d 7d 46 77 20 26 03 41 02 b2 "
}

for i,v in pairs(table) do 
  if __index:GetDescendants() = __value then
    print(v)
    print(i)
  else
    return "not working shutup get out"
    end
end



