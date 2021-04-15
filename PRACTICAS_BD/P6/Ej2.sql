create or replace trigger trigger2
before update on LOCALIDADES for each row       /*Aquí si que debemos de hacer que el trigger salte antes para comprobarlo*/
BEGIN

    if :new.numerohabitantes > 4000000 or :new.numerohabitantes < 1 then 
        :new.numerohabitantes := old.numerohabitantes;      /*No hace falta realizar un insert ya que lo estamos realizando mas arriba*/
    end if;
END;

/*Compilamos*/

select * from LOCALIDADES;      /*Vemos la tabla localidades*/

update localidades set numerohabitantes=0 where odlocalidad=1;      /*Actualizamos un parametro para comprobar*/

/*Como el número no es valido, no se esta cambiando el valor debido al trigger, si ponemos un valor dentro del parámetro del trigger, si se cambiará*/