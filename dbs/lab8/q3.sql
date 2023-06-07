set serveroutput on
declare
	doi date;
	dor date;
	days number(10);
	fine number(10);
begin

	doi:='&doi';
	dor:='&dor';
	days:=dor-doi;

	if days>=0 and days<=7 then 
		fine := 0;
	elsif days>=8 and days<=15 then 
		fine := days*1;
	elsif days>=16 and days<=30 then 
		fine := days*2;
	else 
		fine := days*5;
	end if;

	dbms_output.put_line('fine is '||fine);
end;
/