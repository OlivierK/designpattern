#!/usr/bin/env python

import pygtk
pygtk.require('2.0')
import gtk
import kernel

class Table:
    # Our callback.
    # The data passed to this method is printed to stdout
    def callbackENTER(self, widget, data=None):
        print "callbackENTER - %s was pressed" kernel.eval("1 + 1")

    def callbackDUP(self, widget, data=None):
        print "callbackDUP - %s was pressed" % data 

    def callbackCOMPOSE(self, widget, data=None):
        print "callbackCOMPOSE - %s was pressed" % data

    # This callback quits the program
    def delete_event(self, widget, event, data=None):
        gtk.main_quit()
        return False

    def enter_callback(self, widget, entry):
        entry_text = entry.get_text()
        print "Texte entre: %s\n" % entry_text
   

    def __init__(self):
        # Create a new window
        self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)

        # Set the window title
        self.window.set_title("Exo 5")

        # Set a handler for delete_event that immediately
        # exits GTK.
        self.window.connect("delete_event", self.delete_event)

        
        self.window.set_size_request(400, 400)
        self.window.set_border_width(10)

        # Create a 4x5 table
        table = gtk.Table(4, 5, True)
        table.set_row_spacings(5)
        table.set_col_spacings(5)
        # Put the table in the main window
        self.window.add(table)

        # Create Enter button
        button = gtk.Button("Enter")

        # When the button is clicked, we call the "callbackENTER" method
        # with a pointer to "Enter" as its argument
        button.connect("clicked", self.callbackENTER, "Enter")


        # Insert Enter into the upper left quadrant of the table
        table.attach(button, 2, 3, 2, 3)

        button.show()

        # Create DUP button

        button = gtk.Button("DUP")

        # When the button is clicked, we call the "callback" method
        # with a pointer to "button 2" as its argument
        button.connect("clicked", self.callbackDUP, "DUP")
        # Insert button 2 into the upper right quadrant of the table
        table.attach(button, 3, 4, 2, 3)

        button.show()

        # Create "STO" button
        button = gtk.Button("STO")

        # When the button is clicked, we call the main_quit function
        # and the program exits
        button.connect("clicked", lambda w: gtk.main_quit())

        # Insert the quit button into the both lower quadrants of the table
        table.attach(button, 4, 5, 2, 3)

        button.show()

        entry = gtk.Entry(0)
       # entry.set_max_length(50)
        entry.connect("activate", self.enter_callback, entry)
        entry.set_text("hello")
        entry.insert_text(" world", len(entry.get_text()))
        entry.select_region(0, len(entry.get_text()))       

        table.attach(entry,0, 2, 2, 3)
        entry.show()

        button = gtk.Button("Compose")

        # When the button is clicked, we call the "callback" method
        # with a pointer to "Compose" as its argument
        button.connect("clicked", self.callbackCOMPOSE, "Compose")
        # Insert Compose into the upper right quadrant of the table
        table.attach(button, 1, 5, 3, 4)

        button.show()

        #Create TexteView
        textview = gtk.TextView()

        buffertexte = textview.get_buffer()
        textview.set_editable(False)
        table.attach(textview,0, 2, 0, 2)
       
        textview.show()

        textview2 = gtk.TextView()
        #textview.set_editable(true)
        buffertexte = textview2.get_buffer()
        table.attach(textview2, 2, 3, 0, 2)
        textview2.show()

        textview3 = gtk.TextView()
        buffertexte = textview3.get_buffer()
        table.attach(textview3, 3, 5, 0, 1)
       
        textview3.show() 

        textview4 = gtk.TextView()
        buffertexte = textview4.get_buffer()
        table.attach(textview4, 3, 5, 1, 2)
       
        textview4.show()

        textview5 = gtk.TextView()
        buffertexte = textview5.get_buffer()
        table.attach(textview5, 0, 1, 3, 4)
       
        textview5.show()

        table.show()
        self.window.show()

def main():
    gtk.main()
    return 0       

if __name__ == "__main__":
    Table()
    main()
