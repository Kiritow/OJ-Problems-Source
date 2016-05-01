var
k,ld,cbs,cd,md,i,x1,x2,x3,x4:integer;
sj:real;
begin
read(k,x1,x2,x3,x4);
sj:=99999999;
for ld:=0 to 10 do
for cbs:=0 to 10 do
for cd:=0 to 10 do
for md:=0 to 10 do
if (ld+cbs+cd+md=k) and (((20-ld*2)*x1+(100-cbs*7)*x2*2/((10+md*1)*x4)+(100-cd*9)*x3/((10+md*1)*x4))<sj) then sj:=(20-ld*2)*x1+(100-cbs*7)*x2*2/((10+md*1)*x4)+(100-cd*9)*x3/((10+md*1)*x4);
write(sj:0:3);
end.
