/*
 * rbbst.h
 *
 * Date        Author    Notes
 * =====================================================
 * 2014-04-14  Kempe     Initial version
 * 2015-04-06  Redekopp  Updated formatting and removed
 *                         KeyExistsException
 */
#ifndef RBBST_H
#define RBBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include "bst.h"
#include <iostream>

/* -----------------------------------------------------
 * Red-Black Nodes and Search Tree
 ------------------------------------------------------*/

enum Color {red, black};

template <class KeyType, class ValueType>
class RedBlackNode : public Node<KeyType, ValueType>
{
public:
  RedBlackNode (KeyType k, ValueType v, RedBlackNode<KeyType, ValueType> *p)
    : Node<KeyType, ValueType> (k, v, p), color(red) {};
  
  virtual ~RedBlackNode () {}
  
  Color getColor () const
    { return color; }
  
  void setColor (Color c)
    { color = c; }
  
  virtual RedBlackNode<KeyType, ValueType> *getParent () const
    { return (RedBlackNode<KeyType,ValueType>*) this->_parent; }
  
  virtual RedBlackNode<KeyType, ValueType> *getLeft () const
    { return (RedBlackNode<KeyType,ValueType>*) this->_left; }
  
  virtual RedBlackNode<KeyType, ValueType> *getRight () const
    { return (RedBlackNode<KeyType,ValueType>*) this->_right; }
  
 protected:
  Color color;
};

/* -----------------------------------------------------
 * Red-Black Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class RedBlackTree : public BinarySearchTree<KeyType, ValueType>
{
public:
  void insert (const std::pair<const KeyType, ValueType>& new_item){
     RedBlackNode<KeyType,ValueType>* resultnode =  insertRBT(static_cast<RedBlackNode<KeyType,ValueType>*>(this->root), new_item);
     //this->print();
     fixTree(resultnode);

     //ACCOUNT FOR OVERWRITING A VALUE IF IT EXISTS
  }
  /* This one is yours to implement.
     It should insert the (key, value) pair to the tree, 
     making sure that it remains a valid Red-Black Tree.
     If the key is already in the tree
     (with a possibly different associated value),
     then it should overwrite the value with the new one.
     We strongly recommend defining suitable (private) helper functions. */

private:    
  RedBlackNode<KeyType,ValueType>* insertRBT(RedBlackNode<KeyType, ValueType> * node, const std::pair<const KeyType, ValueType>& new_item){
      if ( node == NULL){
         RedBlackNode<KeyType, ValueType>* firstnode = new RedBlackNode<KeyType, ValueType>(new_item.first,new_item.second, NULL);
         firstnode->setColor(black);
         this->root = firstnode;
         return firstnode;
      }
      else if (new_item.first == node->getKey()){
          node->setValue(new_item.second);
          return node;
      }
      else if (node->getLeft() == NULL && new_item.first < node->getKey()){
         RedBlackNode<KeyType, ValueType>* l = new RedBlackNode<KeyType,ValueType>(new_item.first, new_item.second, node);
         node->setLeft(l);
         return l;
      }
      else if(node->getRight() == NULL && new_item.first > node->getKey()){
         RedBlackNode<KeyType, ValueType>* r = new RedBlackNode<KeyType,ValueType>(new_item.first, new_item.second, node);
         node->setRight(r);
         return r;
      }
      else if ( new_item.first < node->getKey()){
         return insertRBT(node->getLeft(), new_item);
      }
      else{
         return insertRBT(node->getRight(), new_item);
      }
  }

  void fixTree(RedBlackNode<KeyType,ValueType>* node){
      if ( node->getParent() == NULL){
          node->setColor(black);
      }
      else{
          if (node->getParent()->getColor() == red){
        
              RedBlackNode<KeyType, ValueType>* parent = node->getParent();
              RedBlackNode<KeyType, ValueType>* grandParent = parent->getParent();
              RedBlackNode<KeyType,ValueType>* uncle = NULL;
              if (parent == grandParent->getLeft()){
                  uncle = grandParent->getRight();
              }
              else{
                  uncle = grandParent->getLeft();
              }

              if (uncle != NULL){
                  if (uncle->getColor() == red){
                      uncle->setColor(black);
                      parent->setColor(black);
                      grandParent->setColor(red);
                     // std::cout <<"FixTree rec" << std::endl;
                      fixTree(grandParent);
                  }
                  else{
                      //std::cout << "First rotate rec" << std::endl;
                      rotate(node);
                  }
              }
              else{
                 // std::cout << "Second rotate rec" << std::endl;
                  rotate(node);
              }
          }
          else{
               // std::cout <<"MY PARENT IS BLACK MODAFUCKER" << std::endl;
          }  
      }

  }

void rotate(RedBlackNode<KeyType,ValueType>* node){
      
    RedBlackNode<KeyType, ValueType>* parent = node->getParent();
    RedBlackNode<KeyType, ValueType>* grandParent = parent->getParent();
    RedBlackNode<KeyType, ValueType>* greatGrandParent = grandParent->getParent();
    
    if (node == parent->getLeft()){
                  if (parent == grandParent->getLeft()){
                        
                        if (greatGrandParent != NULL){ 
                            if (grandParent == greatGrandParent->getRight()){
                                RedBlackNode<KeyType,ValueType>* temp = parent->getRight();
                                greatGrandParent->setRight(parent);
                                parent->setParent(greatGrandParent);
                                grandParent->setLeft(temp);
                                if (temp != NULL){
                                    temp->setParent(grandParent);
                                }
                                grandParent->setParent(parent);
                                parent->setRight(grandParent);
                                parent->setColor(black);
                                grandParent->setColor(red);
                            }
                            else{
                                RedBlackNode<KeyType,ValueType>* temp = parent->getRight();
                                greatGrandParent->setLeft(parent);
                                parent->setParent(greatGrandParent);
                                grandParent->setLeft(temp);
                                if (temp != NULL){
                                    temp->setParent(grandParent);
                                }
                                grandParent->setParent(parent);
                                parent->setRight(grandParent);
                                parent->setColor(black);
                                grandParent->setColor(red);
                            }
                        }
                        else{   
                                RedBlackNode<KeyType,ValueType>* temp = parent->getRight();
                                this->root = parent;
                                parent->setParent(NULL);
                                grandParent->setLeft(temp);
                                if (temp != NULL){
                                    temp->setParent(grandParent);
                                }
                                grandParent->setParent(parent);
                                parent->setRight(grandParent);
                                parent->setColor(black);
                                grandParent->setColor(red);
                        }
                  }
                  else{  
                        //FIRST ROTATE NODE AND PARENT
                        RedBlackNode<KeyType,ValueType>* temp = node->getRight();
                        grandParent->setRight(node);
                        node->setParent(grandParent);
                        node->setRight(parent);
                        parent->setParent(node);
                        parent->setLeft(temp);
                        if (temp != NULL){
                          temp->setParent(parent);
                        }
                        rotate(parent);                     
                  }

    }
    else if (node == parent->getRight()){
        if (parent == grandParent->getRight()){
              if (greatGrandParent != NULL){
                      if (grandParent == greatGrandParent->getLeft()){
                          RedBlackNode<KeyType,ValueType>* temp = parent->getLeft();
                          greatGrandParent->setLeft(parent);
                          parent->setParent(greatGrandParent);
                          grandParent->setRight(temp);
                          if (temp != NULL){
                            temp->setParent(grandParent);
                          }
                          grandParent->setParent(parent);
                          parent->setLeft(grandParent);
                          parent->setColor(black);
                          grandParent->setColor(red);
                      }
                      else{
                          //std::cout <<"HERE1"<< std::endl;
                          RedBlackNode<KeyType,ValueType>* temp = parent->getLeft();
                          greatGrandParent->setRight(parent);
                          parent->setParent(greatGrandParent);
                          //std::cout <<"HERE2"<< std::endl;
                          grandParent->setRight(temp);
                          //std::cout <<"HERE3"<< std::endl;
                          if (temp != NULL){
                            temp->setParent(grandParent);
                          }
                         // std::cout <<"HERE4"<< std::endl;
                          grandParent->setParent(parent);
                          parent->setLeft(grandParent);
                          parent->setColor(black);
                          grandParent->setColor(red);
                         // std::cout <<"HERE5"<< std::endl;
                      }
              }
              else{   
                      RedBlackNode<KeyType,ValueType>* temp = parent->getLeft();
                      parent->setParent(NULL);
                      this->root = parent;
                      grandParent->setRight(temp);
                      if (temp != NULL){
                            temp->setParent(grandParent);
                      }
                      grandParent->setParent(parent);
                      parent->setLeft(grandParent);
                      parent->setColor(black);
                      grandParent->setColor(red);
              }        
        }
        else{
              //FIRST ROTATE NODE AND PARENT
              RedBlackNode<KeyType,ValueType>* temp = node->getLeft();
              grandParent->setLeft(node);
              node->setParent(grandParent);
              node->setLeft(parent);
              parent->setParent(node);
              parent->setRight(temp);
              if (temp != NULL){
                 temp->setParent(parent);
              }
              rotate(parent);
        }

    }
}

};

#endif
