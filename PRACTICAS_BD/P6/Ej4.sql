after table votantes add constraint check_telefono_lunes_12 check(telefono >= 600000000 and telefono <= 799999999);

/*alter table votantes disable constraint check_telefono_lunes;*/

insert into votantes
values (44433322, 'Antonio Pepe', 'Basicos', 'Estudiante', 'pepeantonio@uco.es', 5, '29/08/1999', 0);

select * from votantes;