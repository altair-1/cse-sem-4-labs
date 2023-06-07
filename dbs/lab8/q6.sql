set SERVEROUTPUT ON 

declare
    G StudentTable.GPA%TYPE;
    MAXG StudentTable.GPA%TYPE;
    N number;
    I number;
begin
    select count(*) 
    into N 
    from StudentTable;
    I := 1;
    MAXG := 0;
    while I <= N
    loop
        select GPA
        into G
        from StudentTable
        where RollNo = I;
        if G > MAXG then
            MAXG := G;
        end if;
        I := I + 1;
    end loop;
    select RollNo 
    into I 
    from StudentTable 
    where GPA = MAXG;
    dbms_output.put_line('student with max. GPA '|| MAXG || ' is roll number ' || I);
end;
/