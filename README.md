# Getting Started with Rational Rhapsody

0. About Rhapsody
1. Getting Started
2. Defining Classes
3. Defining Properties and Operations
4. Defining the Statechart
5. Stepping Through the Model

## 1. About Rhapsody

Rhapsody is a UML-based formal modeling environment that can be used
to simulate and test the behavior of real-time and embedded systems.
You can use Rhapsody to build UML class diagram and statechart as usual,
and then attach actual implementation to the operations in your diagram
and watch Rhapsody step through the states according to the behavior
you've defined. This will help you visualize your program's flow
and help you catch potential design flaws and edge cases you might not
have covered.

This tutorial will walk you through the process of setting up IBM Rational Rhapsody for C++ 8.0 for the first time and creating a simple model of a lightswitch.

## 2. Getting Started

Before you can get started using Rhapsody, you'll need to make certain that the lab computer you are using is configured properly. By default, the computers in the Software Engineering department labs do not have the path set for the Visual Studio 2010 tools which are required
to build projects.

### Fixing Configuration Problems

In order to configure your account on the lab computer so that Rhapsody can find `nmake` and the other tools it needs, follow these steps:

0. Close Rhapsody if it is running.
1. Click the Start icon
2. Click on your user avatar at the top of the Start Menu
3. On the left sidebar of the window that opens, click on "Change my environment variables"
4. Click the "New.." button on the Environment Variables window.
5. Enter `VS_2010_PATH` as the variable name.
6. Enter `C:\Program Files (x86)\Microsoft Visual Studio 10.0` for the variable value.
7. Click "OK" to save your changes.

Once you make this change for your account on one lab computer, you shouldn't have to change it again. However, you may have to make this change on other lab machines you use if your roaming profile does not sync properly.

### Starting Rhapsody and Creating a Project

To get started, launch "IBM Rational Rhapsody for C++ 8.0" from the programs menu. Once Rhapsody finishes launching, you'll be greeted by the "Welcome to Rhapsody" tab.

Create a new project by selecting the "New Project" option in the middle of the welcome screen and enter a project name. Change the "In Folder" to point to a location in your shared drive space. By default, Rhapsody will try to create new projects in the Program Files directory, which you do not have access to and is specific to that lab machine. For now, leave the "Project Type" and "Project Settings" options on "Default" unless your instructor advises you otherwise. Once your press "OK", you'll be greeted with the main project workspace.

## 3. Defining Classes

To create the classes for the LightSwitch tutorial, expand the "Packages" folder in the Entire Model View sidebar. Right-click on the "Packages" folder and click "Add New Package", and give the package a descriptive name. Since this is a simple project and it will consist of only one package, name the package "LightSwitch".

Right click on your new package and click Add New > Diagrams > Class Diagram. Name the diagram something like "Lightswitch Class Diagram" and press enter to continue to a UML editor view. Under the "Diagram Tools" toolbox on the right side of the window, find the "Class" item and drag two copies of it over onto the diagram workspace. Name these classes "Bulb" and "Switch" respectively.

You'll notice after you create "Bulb" and "Switch" that a "Classes" folder has appeared under the "LightSwitch" package. You can manipuate the classes in your diagram from this tree view the same way you can in the diagram view. To give the Bulb a property that indicates whether it is lit, double click on it in the diagram view and select the Attributes tab. Click the spot under the "Name" column where it says "<New>" and enter the name "illuminated", and then change the Type to "bool" and set its Initial Value to "FALSE".

## 4. Defining Properties and Operations

## 5. Defining the Statechart

## 6. Stepping Through the Model