after table eventos disable constraint ck_nombre;

/*Si tenemos dudas de que ha funcionado, realizamos un ejemplo como el de abajo*/

declare 
    ejemplo varchar2(100);

BEGIN
    ejemplo := 'Hola';

    dbms_output.put_line(substr(ejemplo,1,1));
    dbms_output.put_line(substr(ejemplo,-1,1));

    if substr(ejemplo,-1,1)='s' then        /*o if ejemplo like '%s* then*/
        dbms_output.put_line('Es s');
    end if;

    if substr(ejemplo,1,1)= upper(substr(ejemplo,1,1)) then
        dbms_output.put_line('Es mayus');
    end if;
END;


alter table eventos add constraint check_tipo_lunes_12 check(substr(tipo, -1,1)='s' and substr(tipo,1,1)=upper(substr(tipo(1,1))));

insert into eventos values(150, 'mi evento lunes 12', sysdate ,'hola', 'clase BD lunes 12');

select * from eventos;