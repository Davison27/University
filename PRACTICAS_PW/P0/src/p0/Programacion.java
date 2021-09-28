package p0;

import java.util.ArrayList;
import java.util.Date;

public class Programacion {
	
	ArrayList<Espectaculo> ListaEspectaculos;
	
	
	
	public Programacion() {
		this.ListaEspectaculos = new ArrayList<Espectaculo>();
	}

	public void programarEspectaculo(Espectaculo espectaculo) {
		this.ListaEspectaculos.add(espectaculo);
	}
	
	public ArrayList<Espectaculo> verEspectaculos() {
			return this.ListaEspectaculos;
	}
	
	public void imprimirEventos() {
		for(int i=0; i<this.ListaEspectaculos.size(); i++) {
			System.out.println(this.ListaEspectaculos.get(i).toString());
		}
	}
	
	public ArrayList<String> verTitulos() {
		ArrayList<String> ListAux = new ArrayList<String>();
		for(int i=0; i<this.ListaEspectaculos.size(); i++) {
			ListAux.add(this.ListaEspectaculos.get(i).getTitulo());
		}
		return ListAux;
	}
	
	public boolean eliminarEspectaculo(String titulo) {
		for(int i=0; i<this.ListaEspectaculos.size(); i++) {
			if(this.ListaEspectaculos.get(i).getTitulo()==titulo) {
				this.ListaEspectaculos.remove(i);
				return true;
			}
		}
		return false;
	}
	
	public void verProximosEspectaculos(Date fecha) {

	}
	
	public void verEspectaculosDisponibles(categoria cat) {
		ArrayList<String> ListAux = new ArrayList<String>();
		for(int i=0; i< this.ListaEspectaculos.size(); i++) {
			if(this.ListaEspectaculos.get(i).getCategoria()==cat) {
				if(this.ListaEspectaculos.get(i).getLocalidadesVenta() != 0) {
					
				}
				
			}
		}
		if(ListAux.size() == 0) {
			return;
		}
		
		
		
	}

	
}
