create table Client_master (
    client_no number,
    name varchar(20),
    address varchar(50),
    bal_due number,
    primary key (client_no));

insert into Client_master values (1,'Client1','Addr1',20000);
insert into Client_master values (2,'Client2','Addr2',10000);
insert into Client_master values (3,'Client3','Addr3',50000);
insert into Client_master values (4,'Client4','Addr4',80000);

create table auditclient (
    client_no number,
    name varchar(20),
    bal_due number,
    operation varchar(20),
    userid number,
    opdate date);

create or replace trigger auditLog
before update or delete on client_master
for each row
begin
	case
	when updating then
    		insert into auditClient values (:OLD.client_no, :OLD.name, :OLD.bal_due, 'update', 1440, sysdate);
	when deleting then
    		insert into auditClient values (:OLD.client_no, :OLD.name, :OLD.bal_due, 'delete', 1440, sysdate);
	end case;
end;
/