#ifndef BASE_H
#define BASE_H

// open doxywizard
// select working directrory 
// select source folder
// select the folder to add the documentation file- i use docs folder docs

// add project name and a small synospsis and version id-  next next and genrate
// goto docs/html and open index.html

// Files,classes, namespaces etc are shown as tabs if present

//doc_pages folder was created to add the markdown files to create the tutorial type documentation




/// @brief brief description of the class - add this above the class declaration in the header file

///
/// add the detialed descritpion here- leave one empty line to seperate the detailed from the brief. enclose with  asterix to *italic*  **bold**   ***italicbold***
///### Example 1- use three hash- pound symbols to add a another level heading. use upto 6 hash/pound to define the heading level
///####example 1.1
/// can add cpp code blocks using  symbol line and add .cpp , then addd the code block then end with a line of equal number  symbols
///~~~~~~~~~~~~~~~~~~~~~{.cpp}
///Base* ptr= new Base();// comment
///~~~~~~~~~~~~~~~~~~~~~

class Base{

    public:
        int x,y,z;

        /// @brief brief description of the function get, can place this in the header or implementation
        ///
        /// add the detialed descritpion here- leave one empty line to seperate the detailed from the brief
        /// @return dettails of the return of the function- use @ return to reffer to the return decription
        ///@see - use @ see to add links to other fucntions like set(int,int,int). can click on set and go there.(no need to add the ip parameter list)
        ///@note - to add a side note use @ note
        ///@attention- use @ atention to add notes that are of important
        ///@warning - use @ warning to add a note of higher importance
        int get() const;


        /// @brief brief description of the function set, can place this in the header or implementation
        ///
        /// add the detialed descritpion here- leave one empty line to seperate the detailed from the brief
        /// @return dettails of the return of the function
        ///@param x description of the paramter x use @ then the word param and the name of the parameter to reffer to the aprameter
        ///@param y description of the paramter y use @ then the word param and the name of the parameter to reffer to the aprameter
        ///@param z description of the paramter z use @ then the word param and the name of the parameter to reffer to the aprameter
        ///@see - use @ see to add links to other fucntions like get(). can click on get and go there
        ///@note - to add a side note use @ note
        ///@attention- use @ atention to add notes that are of important
        ///@warning - use @ warning to add a note of higher importance
        void set(const int& x=0,const int& y=0, const int& z=0);
};


#endif