#ifndef CWINDOW__H
#define CWINDOW__H

#include <iostream>
#include "color_.h"

class CWindow_
{
private:
	int x_, y_; // Posição na tela
	int cx_, cy_; // Largura e altura

	class Canvas {
	private:
		Color_ text_color_; /* Cor da fonte */
		unsigned int font_size_; /* Tamanho da fonte */
		std::string font_type_; /* Tipo da fonte */
		Color_ line_color_; /* Cor da pena a ser usada para traçar linhas */
		Color_ pencil_color_; /* Cor do pincel a ser usado para preencher regiões fechadas */
		
	public:
		/* Construtor com parâmetros default */
		Canvas (
			const Color_& text_color = Color_(),
			const unsigned int& font_size = 12,
			const std::string& font_type = "Arial",
			const Color_& line_color = Color_(),
			const Color_& pencil_color = Color_(255, 255, 255)
			) : text_color_(text_color), font_size_(font_size), font_type_(font_type), line_color_(line_color), pencil_color_(pencil_color) {}

		/* Métodos para setar (definir) os atributos acima */
		inline void set_text_color(const Color_& new_color) { text_color_ = new_color; }
		inline void set_font_size(const unsigned int& new_size) { font_size_ = new_size; }
		inline void set_font_type(const std::string& new_type) { font_type_ = new_type; }
		inline void set_line_color(const Color_& new_color) { line_color_ = new_color; }
		inline void set_pencil_color(const Color_& new_color) { pencil_color_ = new_color; }
		
		/* Métodos para retornar os atributos acima */
		inline Color_ text_color(void) const { return text_color_; }
		inline unsigned int font_size(void) const { return font_size_; }
		inline std::string font_type(void) const { return font_type_; }
		inline Color_ line_color(void) const { return line_color_; }
		inline Color_ pencil_color(void) const { return pencil_color_; }
	};
	
	/* Ponteiro para classe aninhada Canvas */
	Canvas* my_canvas_;

public:

	/* Construtor que, entre outras coisas, aloca o objeto my_canvas_ */
	CWindow_(const int& x, const int& y, const int& cx, const int& cy) : x_(x), y_(y), cx_(cx), cy_(cy), my_canvas_(new Canvas()) { }

	/* Destrutor que desaloca o my_canvas_ */
	~CWindow_(void) { delete my_canvas_; }

	void show(void); // Mostra na tela
	int cleanup(void) { delete my_canvas_; my_canvas_ = new Canvas(); } // Limpa a tela

	/* Ao se efetuar uma chamada aos métodos abaixo, o método show() será chamado automaticamente */
	inline void move(const int& x, const int& y) { x_ = x; y_ = y; show(); }
	inline void resize(const int& cx, const int& cy) { cx_ = cx; cy_ = cy; show(); } // Redimensiona

	void textOut(const int& x = 0, const int& y = 0, const std::string& text = "") const; // Texto em x, y

	/* Métodos correspondentes aos da classe Canvas */
	inline void setTextColor(const Color_& cor) { my_canvas_->set_text_color(cor); }
	inline void setFontSize(const unsigned int& tamanho) { my_canvas_->set_font_size(tamanho); }
	inline void setFontType(const std::string& fonte) { my_canvas_->set_font_type(fonte); }
	inline void setLineColor(const Color_& cor) { my_canvas_->set_line_color(cor); }
	inline void setPencilColor(const Color_& cor) { my_canvas_->set_pencil_color(cor); }

	inline Color_ getTextColor(void) const { return my_canvas_->text_color(); }
	inline unsigned int getFontSize(void) const { return my_canvas_->font_size(); }
	inline std::string getFontType(void) const { return my_canvas_->font_type(); }
	inline Color_ getLineColor(void) const { return my_canvas_->line_color(); }
	inline Color_ getPencilColor(void) const { return my_canvas_->pencil_color(); }

	/* Método que grava os atributos da classe em um arquivo em disco */
	void gravar(void);

};

#endif // CWINDOW__H ///