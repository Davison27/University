package p0;

import java.util.Date;

public class Espectaculo {
	
	private String espectaculo_;
	
	public enum categoria{
		concierto, monologo, obra;
	}
	
	private categoria categoria;
	
	private String descripcion_;
	
	private Date fecha_;
	
	private int ventas_;
	
	private int vendidas_;
	
	
	
	public Espectaculo() {
		
	}
	
	public Espectaculo(String titulo, categoria categoria, String descripcion) {
		this.espectaculo_=titulo;
		this.categoria=categoria;
		this.descripcion_=descripcion;
	}
	
	
	
	public void setLocalidadesVenta(int ventas) {
		this.ventas_=ventas;
	}
	
	public void setLocalidadVendida(int vendidas) {
		this.vendidas_=vendidas;
	}
	
	public void setFecha(Date fecha) {
		this.fecha_=fecha;
	}
	
	public void setDescripcion(String descripcion) {
		this.descripcion_=descripcion;
	}
	
	public void setCategoria(int categoria) {
		this.categoria=categoria;
	}
	
	public void setTitulo(String titulo) {
		this.espectaculo_=titulo;
	}
	
	
	
	public int getLocalidadesVenta() {
		return this.ventas_;
	}
	
	
	public int getLocalidadesVendida() {
		return this.vendidas_;
	}
	
	public Date getFecha() {
		return this.fecha_;
	}
	
	public String getDescripcion() {
		return this.descripcion_;
	}
	
	public int getCategoria() {
		return this.categoria;
	}
	
	public String getTitulo() {
		return this.espectaculo_;
	}
	
	public String toString() {
		return "Titulo= "+this.espectaculo_+
				"Categoria= "+this.categoria_+
				"Descripción= "+this.descripcion_+
				"Fecha= "+this.fecha_+
				"Ventas= "+this.ventas_+
				"Vendidas= "+this.vendidas_;
	}

	
	
}
