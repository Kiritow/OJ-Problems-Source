var i,j,n:longint;map:array[0..1024,0..2048]of char;a:array[0..11]of longint;
procedure draw(x,y,n:longint);
begin
  if n=1 then
    begin
      map[x,y]:='/';map[x,y+1]:='_';map[x,y+2]:='_';map[x,y+3]:='\';
      map[x+1,y+1]:='/';map[x+1,y+2]:='\';
    end
  else begin draw(x,y,n-1);draw(x+a[n-1],y+a[n-1],n-1);draw(x,y+a[n],n-1);end;
end;
begin
  for i:=1 to 1024 do
    for j:=1 to 2048 do
      map[i,j]:=' ';
  a[0]:=1;readln(n);
  for i:=1 to 11 do a[i]:=a[i-1]*2;
  draw(1,1,n);
  for i:=a[n] downto 1 do
    begin
      for j:=1 to a[n]+(a[n]-i+1) do write(map[i,j]);
      writeln;
    end;
end.
