/*3. Implemente una funcionalidad que no permita que se inserten direcciones de

correo inválidas en la tabla ?VOTANTES?.

Para que sea una dirección válida debe comenzar con una secuencia de caracteres

(longitud > 0), seguido del caracter ?@?, seguido de una secuencia de caracteres

(longitud > 0), luego ?.?, y finalmente una secuencia de caracteres (longitud > 1).

Puede asumir que en el caso del caracter ?.? solo aparecerá como máximo en 1 ocasión.

Ejemplos de direcciones inválidas: @gmail.com, juangmail.com, juan@.com, juan@gmailcom, juan@gmail.c */


/*ESTE ES UN EJEMPLO*/

declare

    ejemplo varchar2(100);

BEGIN

    ejemplo := 'ejemplo@uco.es';

    /*POSICION DEL @*/
    dbms_output.put_line(instr(ejemplo,'@'));   -------> instr(ejemplo,'@') > 1

    /*POSICION DEL .*/
    dbms_output.put_line(instr(ejemplo,'.', instr(ejemplo,'@')));       /*Ponemos el @ para que nos encuentre el punto DESPUES del @ y no antes*/

    /*@ Y . NO PUEDEN ESTAR CONSECUTIVOS*/
    dbms_output.put_line(instr(ejemplo,'.', instr(ejemplo,'@'))); ------> instr(ejemplo, '.', instr(ejemplo,'@')) -instr(ejemplo,'@') >1

    /*PARA LA COMPROBACION DEL 0*/
    dbms_output.put_line(length(ejemplo)); -----> instr(ejemplo,'.', instr(ejemplo,'@')) < length(ejemplo)
END;




/*ESTA ES LA SOLUCION*/

alter table votantes add constraint check_correo_lunes_12 check(instr(email,'@')>1 and
instr(email,'.', instr(email,'@')) -instr(email,'@') >1 and
instr(email,'.', instr(email,'@')) < length(email);

alter table votantes disable constraint ck_lunes_correo;

insert into votantes values(400000000, 'paco pepe', 'Basicos', .....) /*EJEMPLO DE COMPROBACION*/

select * from votantes;
