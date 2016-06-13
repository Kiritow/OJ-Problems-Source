uses math;
var map,dp:array[0..500,0..500] of longint;
  r,c,i,j,ans:longint;

function search(x,y:longint):longint;
var res:longint;
begin
  res:=1;
  if dp[x,y]<>0 then exit(dp[x,y]);
  if (x>1) and (map[x-1,y]<map[x,y]) then res:=max(res,search(x-1,y)+1);
  if (y>1) and (map[x,y-1]<map[x,y]) then res:=max(res,search(x,y-1)+1);
  if (x<r) and (map[x+1,y]<map[x,y]) then res:=max(res,search(x+1,y)+1);
  if (y<c) and (map[x,y+1]<map[x,y]) then res:=max(res,search(x,y+1)+1);
  dp[x,y]:=res;
  exit(res);
end;

begin
  read(r,c);
  for i:=1 to r do
    for j:=1 to c do
      read(map[i,j]);
  ans:=1;
  fillchar(dp,sizeof(dp),0);

  for i:=1 to r do
    for j:=1 to c do
      ans:=max(ans,search(i,j));
  write(ans);
end.
