set SERVEROUTPUT ON

declare 
    Out_Of_Range exception;
    G StudentTable.GPA%TYPE;
    I number;
    N number;
begin
    select count(*) 
    into N from StudentTable;
    I := 1;
    while I <= N
    loop
        select GPA
        into G
        from StudentTable
        where RollNo = I;
        if G < 0 AND G > 10 then
            raise Out_Of_Range;
        end if;
        I := I + 1;
    end loop;
    exception 
	when Out_Of_Range then
		dbms_output.put_line('gpa is out of range');
end;
/