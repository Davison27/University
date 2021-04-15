create or replace trigger trigger1
after update on eventos for each row             /*En este caso me da igual pero si tengo que manipular un variable si tengo que hacerlo antes, pero como voy a guardar las dos juntas me va a dar igual poner before que after*/

BEGIN
    insert into AUDIT_TABLE values(:old.nombre||:new.nombre,'eventos');

END;

/*Compilamos*/

select * from eventos;          /*Vemos lo que hay en la tabla eventos*/

update eventos set nombre='clase lunes' where idevento=30;      /*Actualizamos la tabla eventos*/

select * from AUDIT_TABLE;      /*Vemos que se ha cambiado bien*/