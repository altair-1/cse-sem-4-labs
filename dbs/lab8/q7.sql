set serveroutput on
declare
	grade char(2);
	x number := 0;
	pl_gpa StudentTable.gpa%TYPE;
begin

	<<back>>

	x := x+1;

	select gpa 
	into pl_gpa
	from StudentTable
	where rollno=x;

	if pl_gpa>=0 and pl_gpa<4 then 
		grade :='F';
	elsif pl_gpa>=4 and pl_gpa<5 then 
		grade :='E';
	elsif pl_gpa>=5 and pl_gpa<6 then 
		grade :='D';
	elsif pl_gpa>=6 and pl_gpa<7 then 
		grade :='C';
	elsif pl_gpa>=7 and pl_gpa<8 then 
		grade :='B';
	elsif pl_gpa>=8 and pl_gpa<9 then 
		grade :='A';
	else 
		grade :='A+';
	end if;

	goto print;

	<<print>>
	
	dbms_output.put_line('grade for '||pl_gpa||' is '||grade);
	if x<5 then 
		goto back;
	end if;
end;
/