#ifndef __ED_SList_HPP__
#define __ED_SList_HPP__

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

/** @brief a single link node.*/
template <class T>
class SNode
{
public:

    /** @brief Define a shared reference to a SNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< SNode<T> > Ref;

    /** @name Life cicle.*/
    /** @{*/

    /** @brief Create a node.
     * @post !has_next()
     */
    SNode (T const& it)
    {
        valor_=it;                                          
        siguiente_=nullptr;                                 
        assert(!has_next());
    }

    /** @brief Create an empty Stack.*/
    SNode (T const& it, SNode<T>::Ref& next)
    {
        //TODO
        valor_=it;                                          
        siguiente_=next;                                    
    }

    /**
     * @brief Create a SNode using dynamic memory.
     * @param it the value save in the node.
     * @param next link to the next node.
     * @return a shared referente to the new node.
     */
    static typename SNode<T>::Ref create(T const& it, SNode<T>::Ref next=nullptr)
    {
        return std::make_shared<SNode<T>> (it, next);
    }

    /** @brief Destroy a SNode.**/
    ~SNode()                                                //Al usar puntero inteligentes, no nos hace falta hacer el destructor
    {
        //TODO: think if it is needed.
    }
    /** @}*/

    /** @name Observers.*/
    /** @{*/

    /** @brief Get the data item.*/
    const T& item() const
    {
        //TODO
        return valor_;
    }

    /**
     * @brief Has it a next node?.
     * @return true if it has a next node.
    */
    bool has_next() const
    {
        //TODO
        return siguiente_ != nullptr;
    }

    /** @brief Get the link to next element.*/
    SNode<T>::Ref next() const
    {
        //TODO
        return siguiente_;
    }

    /** @}*/

    /** @name Modifiers.*/
    /** @{*/

    /** @brief Set the data item.*/
    void set_item(const T& new_it)
    {
        //TODO
        valor_=new_it;
    }

    /** @brief Set the link to the next node.*/
    void set_next(SNode<T>::Ref next)
    {
        //TODO
        siguiente_=next;
    }

protected:

    //TODO

    T valor_;                                   //Guardamos el valor del nodo
    SNode<T>::Ref siguiente_;                   //Puntero al siguiente nodo
};

/**
 * @brief ADT SList.
 * Models a Single linked list[T].
 */
template<class T>
class SList
{
  public:

    /** @brief Define a shared reference to a SNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< SList<T> > Ref;

  /** @name Life cicle.*/
  /** @{*/

  /** @brief Create an empty Stack.
   * @post is_empty()
   */
  SList ()
  {
      //TODO
        head_=nullptr;                  //Le asignamos a head_ un puntero a NULL
        current_=nullptr;               //Le asignamos a current_ un puntero a NULL
      assert(is_empty());
  }

  /** @brief Destroy a Stack.**/
  ~SList()
  {
  }

  /**
   * @brief Create a SList using dynamic memory.
   * @return a shared referente to the new slist.
   */
  static typename SList<T>::Ref create()
  {
      return std::make_shared<SList<T>> ();
  }

  /**
   * @brief Create a SList unfoldig from an input stream.
   *
   * The input format will be "[]" for the empty list
   * or "[" item1 item2 ... item_n "]" where item1 is the head.
   *
   * @param in is the input stream.
   * @warning if the input format is not correct a std::runtime_error with
   * what message "Wrong input format." will be reaised.
   * @return A shared referente to the new slist.
   */
  static typename SList<T>::Ref create(std::istream& in) noexcept(false)
  {      
        auto list = SList<T>::create();

      //TODO
      //Hint: use std::istringstream to convert a token into generic T type.
        auto list_aux = SList<T>::create();                     //Declaramos una lista auxiliar 
        std::string lee;                                        //Declaramos un string 
        T data;                                                 //Declaramos una variable de tipo T
        in>>lee;                                                //Metemos en la variable lee todo el contenido hasta el primer espacio

        if(lee=="[]"){                                          //Si la variable lee posee dos paréntesis sin contenido dentro, devolvemos la lista
            return list;
        }

        if(lee !="["){                                          //Si la variable lee no empieza con un paréntesis, entonces lanzamos un mensaje de error al usuario
            throw std::runtime_error("Wrong input format.");
        }

        while(in>>lee){
            if(lee=="]"){break;}                                //Si lee posee un paréntesis cerrado, entonces hemos terminado
            std::istringstream str(lee);                        //Metemos el valor del stream lee en el string str
            str>>data;                                          //Metemos el valor del str en la variable data 

            list_aux->push_front(data);                         //Ponemos el valor de data en la primera posición de la lista auxiliar
        }

        while(!list_aux->is_empty()){                           //Mientras la lista auxiliar no este vacia, hacemos el bucle
            list->push_front(list_aux->front());                //Metemos al principio de la lista list el valor primero de la lista auxiliar
            list_aux->pop_front();                              //Sacamos el primer valor de la lista auxiliar
        }

        if(lee !="]"){                                          //Si lee es distinto del paréntesis cerrado, entonces lanzamos un aviso
            throw std::runtime_error("Wrong input format.");
        }

        return list;
  }

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const
  {
      //TODO
      if(head_ == nullptr){
          return true;
      }
      return false;                                  //Devolvemos true si head_ es un puntero a NULL, en caso contrario devolvemos false
  }

  /**
   * @brief Get the head's item of the list.
   * @return the item at the head.
   */
  const T& front() const
  {
      assert(!is_empty());
      //TODO
      
      return head_->item();                                     //Devolvemos el item de la variable head_
  }

  /** @brief get the current item.
   * @pre not is_empty()
   */
  const T& current() const
  {
      assert(! is_empty());
      //TODO
      return current_->item();                                  //Devolvemos el item de la variable current_
  }

  /**
   * @brief Is there a next item?
   * @return true if there is.
   * @pre !is_empty()
   */
  bool has_next() const
  {
      assert(!is_empty());
      //TODO
      return current_->has_next();
  }

  /**
   * @brief Get the next item.
   * @return the next item data.
   * @pre has_next()
   */
  T const& next() const
  {
      assert(has_next());
      //TODO
      return current_->next()->item();
  }


  /**
   * @brief Has it the item data?
   * @param[in] it is the item to find.
   * @return true if the item is into the list.
   */
  bool has(T const& it) const
  {
      //TODO
        typename SNode<T>::Ref i = head_;                       //Creamos una variable auxiliar a la que le pasamos los valores de head_;

        if(is_empty()){                                        //Declaramos la primera condición que es si la lista esta vacía, entonces devolvemos false 
            return false;
        }

        if(i->item() == it){                                    //Declaramos la segunda condición que es si el 1º item de la lista es el item que buscamos, entonces devolvemos true
            return true;
        }

        while(i->has_next()){                                   //Declaramos la última condición que es un bucle en donde buscará por todos los items restantes de la lista hasta encontrar uno parecido, si no lo encuentra salimos y devolvemos false
            i = i->next();
            if(i->item()==it){
                return true;
            }
        }
      return false;
  }

  /**
   * @brief Fold to an output stream.
   *
   * The format will be "[]" for the empty list or  '[' item1 item2 item3 ... item_n ']'
   * where item1 is the head.
   *
   * @param out is the output stream.
   * @return the output stream.
   */

  void fold(std::ostream& out) const
  {
      //TODO
        typename SNode<T>::Ref cursor = head_;

        out<<"[";
        if (cursor != nullptr){
            out<<" "<<head_->item();
            while(cursor->has_next()){
                cursor=cursor->next();
                out <<" "<< cursor->item();
            }
            out<<" ";
        }
        out<<"]";
  }

  /**@}*/

  /** @name Modifiers*/

  /** @{*/

  /**
   * @brief Set a new value for current.
   * @param new_v is the new value.
   * @pre !is_empty()
   * @post item()==new_v
   */
  void set_current(T const& new_v)
  {
      assert(!is_empty());
      //TODO

        current_ -> set_item(new_v);                                //Le asiganmos a current_ el nuevo valor con la función set_item
      assert(current()==new_v);
  }


  /**
   * @brief insert an item as the new list's head.
   * @param new_it is the item to insert.
   * @post head()==new_it
   */
  void push_front(T const& new_it)
  {
      //TODO
        auto i = SNode<T>::create(new_it, head_);
        if (current_ == head_){
            current_ = i;
        }
        head_ = i;
      assert(front()==new_it);
  }


  /**
   * @brief insert a new item before current.
   * @param new_it is the item to insert.
   * @post old.is_empty() implies item()==head()==new_it
   * @post !old.is_empty() implies item()==old.item() && has_next() && next()==new_it
   */
  void insert(T const& new_it)
  {
#ifndef NDEBUG
      auto old_is_empty = is_empty();
      T old_item;
      if (!old_is_empty)
          old_item = current ();
#endif

      //TODO
        if (is_empty()){
            push_front(new_it);
            current_ = head_;
            anterior_ = nullptr;
        }
        else if (current_ !=head_){
            typename SNode<T>::Ref i = SNode<T>::create(new_it, current_->next());
            current_->set_next(i);
        }
        else{
            typename SNode<T>::Ref i = SNode<T>::create(new_it, current_->next());
            current_->set_next(i);
        }

      assert(!old_is_empty || (front()==new_it && current()==new_it));
      assert(old_is_empty || (old_item == current() && has_next() && next()==new_it));
  }

  /**
   * @brief Remove the head.
   * @prec !is_empty()
   * @post is_empty() || head() == "next of old.head()".
   */
  void pop_front()
  {
      assert(!is_empty());
      //TODO
        if(current_ == head_){                                  //Si current_ posee el mismo valor que head, entonces le asiganmos a current_ el siguiente valor de head_
            current_ = head_->next();
        }
      head_ = head_->next();                                    //Para remover el valor de head_, lo único que debemos de hacer es asignarle su siguiente valor
  }


  /**
   * @brief Remove current item.
   * @pre !is_empty()
   * @post old.has_next() implies current()==old.next()
   * @post !old.has_next() implies is_empty() || current()=="old previous item."
   */
  void remove()
  {
      assert(!is_empty());
#ifndef NDEBUG
      bool old_has_next = has_next();
      T old_next;
      if (has_next())
          old_next=next();
#endif

      //TODO:
      //Study three cases: remove from head, remove from last and
      //remove from middle.
      if (current_ == head_){
            pop_front();
            current_ = head_;
            anterior_ = nullptr;
        }
        else{
            if (current_->has_next()){
                anterior_->set_next(current_->next());
                current_ = current_->next();
            }
            else{
                find(anterior_->item());
                current_->set_next(nullptr);
            }
        }

      assert(!old_has_next || current()==old_next);
  }

  /**
   * @brief Move the cursor to the next list's item.
   * @pre has_next()
   * @post old.next()==current()
   */
  void goto_next()
  {
      assert(has_next());      
#ifndef NDEBUG
      auto old_next = next();
#endif

      //TODO

    anterior_ = current_;                                   //Guardamos en anterior_ el valor de current_
    current_ = current_->next();                            //Le asiganmos a current su siguiente valor

      assert(current()==old_next);
  }

  /**
   * @brief Move the cursor to the list's head.
   * @pre !is_empty()
   * @post current()==front()
   */
  void goto_first()
  {
      assert(!is_empty());
      //TODO
        anterior_ = nullptr; 
        current_ = head_;

      assert(current()==front());
  }

  /**
   * @brief Move the cursor to the first occurrence of a value from the head of the list.
   * If the item is not found, the cursor will be at the end of the list.
   * @param it is the value to be found.
   * @return true if it is found.
   * @pre !is_empty()
   * @post !ret_val || item()==it
   * @post ret_value || !has_next()
   */
  bool find(T const& it)
  {
      assert(!is_empty());
      bool found = false;
      //TODO
        current_ = head_;                                       //Current pasa a tener la direccion de head que es un puntero al primer item de la lista
        anterior_ = nullptr;                                    //A anterior le ponemos el valor de puntero a NULL
        if (current_->item() == it){                            //Si el primer item de la lista es igual que el valor que buscamos, entonces lo hemos encontrado 
            found = true;                        
        }

        if (!found){                                            //Si found no es true, eso quiere decir que aun no lo hemos encontrado
            while (current_->has_next()){                       //Hacemos un bucle que se repetirá mientras current_ posea valores posteriores al actual
                anterior_ = current_;                           //La variable anterior guardará el valor actual de current_
                current_ = current_->next();                    //Current cambia su valor por el siguiente 

                if (current_->item() == it){                    //Si el valor del item de current_ es igual que el valor que buscamos, entonces lo hemos encontrado
                    found = true;                               //Al haberlo encontrado, found = true por lo que salimos del programa
                    break;
                }
            }
        }


      assert(!found || current()==it);
      assert(found || !has_next());
      return found;
  }

  /**
   * @brief Move the cursor to the next occurrence of a value from current.
   * If the item is not found, the cursor will be at the end of the list.
   * @param it is the value to be found.
   * @return true if it is found.
   * @pre has_next()
   * @post !ret_val || item()==it
   * @post ret_value || !has_next()
   */
  bool find_next(T const& it)
  {
      assert(has_next());
      bool found = false;
      //TODO

      while (current_->has_next()){                                 //creamos un bucle en donde iremos pasando por lo diferentes valores del cursor current_ hasta encontrar el valor pasado o hasta el final de la lista
            anterior_ = current_;
            current_ = current_->next();
            if (current_->item() == it){
                found = true;
                break;                                              //si lo hemos encontrado, entonces terminamos el proceso y salimos
            }
        }

      assert(!found || current()==it);
      assert(found || !has_next());
      return found;
  }

  /** @}*/


protected:

    typename SNode<T>::Ref head_;
    typename SNode<T>::Ref current_;
    typename SNode<T>::Ref anterior_;

  //TODO

};

#endif //ED_SList

