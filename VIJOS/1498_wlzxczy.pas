var
m,n,k,l,d,q,w,e,r,i,j,max,u,f:longint;
a,b,uu:array[1..1000]of longint;
procedure sw(var i,j:longint);
var p:longint;
begin
p:=uu[i];uu[i]:=uu[j];uu[j]:=p;
inc(i);dec(j);
end;
procedure qsort(i,j:longint);
var l,r,mid:longint;
begin
l:=i;r:=j;mid:=uu[(l+r) div 2];
repeat
while uu[i]<mid do inc(i); while uu[j]>mid do dec(j);
if i<=j then sw(i,j);
until i>j;
if i<r then qsort(i,r); if l<j then qsort(l,j); end; begin readln(m,n,k,l,d); for i:=1 to d do begin readln(q,w,e,r); if q=e then if w<r then inc(a[w]) else inc(a[r]); if w=r then if q<e then inc(b[q]) else inc(b[e]); end; for i:=1 to k do begin max:=0; for j:=1 to m-1 do if b[j]>max then begin max:=b[j];f:=j; end;
inc(u);uu[u]:=f;b[f]:=0;
end;
qsort(1,u);
for i:=1 to u-1 do write(uu[i],' ');
writeln(uu[u]);
u:=0;
for i:=1 to l do
begin max:=0;
for j:=1 to n-1 do
if a[j]>max then begin max:=a[j];f:=j; end;
inc(u);uu[u]:=f;a[f]:=0;
end;
qsort(1,u);
for i:=1 to u-1 do write(uu[i],' ');
writeln(uu[u]);
end.
