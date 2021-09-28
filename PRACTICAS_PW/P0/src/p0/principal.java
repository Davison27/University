package p0;


public class principal {

	public static void main() {
		Programacion p1 = new Programacion();
		
		System.out.println("Añadiendo dos espectáculos al programa");
		for(int i=2; i<2; i++) {

		}
		
		System.out.println("Añadiendo otros dos espectáculos al programa");
		for(int i=2; i<2; i++) {
			
		}
		
		System.out.println("Ahora vamos a imprimir los títulos de los espectáculos");
		p1.verTitulos();
		
		System.out.println("Ahora vamos a imprimir los próximos espectáculos");
		p1.verProximosEspectaculos(null);
		System.out.println("Ahora vamos a imrpimri los próximos eventos pero con una fecha erronea");
		p1.verProximosEspectaculos(null);
		
		System.out.println("Ahora vamos a ver los espectáculos disponibles dependiendo de la categoria");
		for(int i=1; i<=2; i++) {
			p1.verEspectaculosDisponibles(i);
		}
		
		System.out.println("Vamos a eliminar un espectáculo");
		p1.eliminarEspectaculo(null);
		
		System.out.println("Vamos a ver que espectáculos nos quedan disponibles");
		p1.imprimirEventos();
		
	}
	
}
