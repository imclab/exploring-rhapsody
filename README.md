# Getting Started with Rational Rhapsody

0. About Rhapsody
1. Getting Started
2. Defining Classes
3. Defining Properties and Operations
4. Defining the Statechart
5. Stepping Through the Model
6. Attaching a Test Interface

## 1. About Rhapsody

Rhapsody is a UML-based formal modeling environment that can be used to simulate and test the behavior of real-time and embedded systems. You can use Rhapsody to build UML class diagram and statechart as usual, and then attach actual implementation to the operations in your diagram and watch Rhapsody step through the states according to the behavior
you've defined. This will help you visualize your program's flow and help you catch potential design flaws and edge cases you might not have covered.

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

### Figure 1. Setting environment variables
![Screenshot of setting environment variables](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/1-environment_variables.png)

Once you make this change for your account on one lab computer, you shouldn't have to change it again. However, you may have to make this change on other lab machines you use if your roaming profile does not sync properly.

### Starting Rhapsody and Creating a Project

To get started, launch "IBM Rational Rhapsody for C++ 8.0" from the programs menu. Once Rhapsody finishes launching, you'll be greeted by the "Welcome to Rhapsody" tab.

Create a new project by selecting the "New Project" option in the middle of the welcome screen and enter a project name. Change the "In Folder" to point to a location in your shared drive space. By default, Rhapsody will try to create new projects in the Program Files directory, which you do not have access to and is specific to that lab machine. For now, leave the "Project Type" and "Project Settings" options on "Default" unless your instructor advises you otherwise. Once your press "OK", you'll be greeted with the main project workspace.

### Figure 2. The Rhapsody project workspace
![Screenshot of the project workspace](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/2-rhapsody_workspace.png)

## 3. Defining Classes

To create the classes for the LightSwitch tutorial, expand the "Packages" folder in the Entire Model View sidebar. Right-click on the "Packages" folder and click "Add New Package", and give the package a descriptive name. Since this is a simple project and it will consist of only one package, name the package "LightSwitch".

Right click on your new package and click `Add New > Diagrams > Class Diagram`. Name the diagram something like "Lightswitch Class Diagram" and press enter to continue to a UML editor view. Under the "Diagram Tools" toolbox on the right side of the window, find the "Class" item and drag two copies of it over onto the diagram workspace. Name these classes "Bulb" and "Switch" respectively.

You'll notice after you create "Bulb" and "Switch" that a "Classes" folder has appeared under the "LightSwitch" package. You can manipuate the classes in your diagram from this tree view the same way you can in the diagram view. To give the Bulb a property that indicates whether it is lit, double click on it in the diagram view and select the Attributes tab. Click the spot under the "Name" column where it says "<New>" and enter the name "illuminated", and then change the Type to "bool" and set its Initial Value to "FALSE".

Click on the Directed Association tool on the right hand toolbar, and draw a line from Switch to Bulb. This will cause Switch to own an instance of Bulb, and by default this property on the Switch class will be called `itsBulb`.

### Figure 3. The Class Diagram
![Screenshot of the class diagram](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/3-class_diagram.png)

## 4. Defining Operations

The next step in setting up your lightswitch model is to set up the operation that will represent flipping the switch to turn the light on or off. Operations are methods on a class, and they can have C++ code attached to them that can be executed when the model is run.

Double click on the Switch on your class diagram, and select the Operations tab when the Class:Switch properties window opens. Click the `<New>` in the operations list and name your new operation 'flip', and then double click on the green operation icon to the left of `flip` to bring up the Operation:flip() properties window.

### Figure 4. Defining the flip() operation
![Screenshot of defining flip() in the operation properties window](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/4-defining_flip.png)

Ensure that flip() is defined as a `public`, `void` function, and then click on the Implementation tab. To cause the light to turn on and off when the switch is flipped, enter the line `itsBulb->GEN(toggle());`. This statement is a directive to Rhapsody's model engine that will tell it to trigger a 'toggle' transition in the Bulb's statechart when `flip()` is called. However, we haven't yet created the statechart that defines the Bulb's behavior.

## 5. Defining the Statechart

The Bulb will toggle between the lit and unlit state when the Switch is flipped. To represent this, we will create a statechart for the Bulb. Right click on the Bulb class in the model view sidebar and click `Add New > Diagrams > Statechart`. Name it something like "Bulb Statechart" and click OK to close the creation dialog, and then double click on your newly created statechart diagram in the model viewer to open it in the main workspace.

Drag a State over from the toolbox on the right and name it "Active", and then expand it to fill the window. This state will encapsulate the rest of the Bulb's behavior. To represent that the Bulb can be lit or off, drag two states over from the toolbox into the "Active" state, and name them "ON" and "OFF" respectively. To have the lightbulb simulation always start in the off position, choose the "Default Transition" tool and drag a line from an empty point in the "Active" state to the "OFF" state you just created.

To create a cycle between the lit and unlit states, choose the "Transition" tool and drag a line from "ON" to "OFF" and vise versa. When you release dragging on each of the lines, the cursor will appear to allow you to enter in a trigger for the state transition. Enter 'toggle' both times. This will automatically create a special receiver operation on the Bulb to handle the transition. As long as you use the same transition name you used earlier in the `itsBulb->GEN(toggle())` line from the flip operation on the Switch, you can use any name you like and you will not have to do anything additional to get the Bulb to change states properly.

### Figure 5. The Completed Statechart
![Screenshot of the completed statechart.](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/5-statechart.png)

## 6. Stepping Through the Model

Now that you've finished creating your model and setting up the statechart you can try to build and animate your model. Animating your model will allow you to view each of the state transitions and, with more complex models, help you catch edges cases you may have overlooked. First, expand `Components > DefaultComponent > Configurations > DefaultConfig` in the model viewer, and then double click on `DefaultConfig` to open up the configuration properties window. Select the `Settings` tab and change the Instrumentation Model to Animation.

### Figure 6. Creating Instances of Your Classes
![Screenshot of completed object model diagram](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/6-object_model_diagram.png)

We next need to create an instance of each of the Switch and Bulb classes. To start, right click on the LightSwitch package in the model viewer, and select `Add New > Diagrams > Object Model Diagram`. Name your diagram something like "LightSwitch Object Model" and then make sure that the 'populate diagram' checkbox is unchecked before clicking OK. Then, click and drag a copy of the Bulb and Switch classes from the model viewer into the main workspace for the object model diagram. Once you've placed the classes in the diagram, right click on each of the class boxes and click `Make an Object`. This will cause the Bulb and Switch class boxes in the object model diagram to be replaced with an object for itsBulb and itsSwitch respectively.

### Figure 7. The Build Toolbar
![Screenshot of the build toolbar](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/7-build_toolbar.png)

Now you can finally build your model. Click the `Generate/Make/Run` button on the build toolbar to start Rhapsody building the C++ source that it generated for your model. It will take Rhapsody a moment or two to finish building, but if everything went well you'll soon see "Build Done" in the build window at the bottom of the screen and a blank terminal window will open up which indicates that the model is running.

### Figure 8. The Build Window
![Screenshot of the build window](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/8-build_window.png)

Now you can start to play with the statechart for the Bulb that you created. From the Tools menu select the `Animated Statechart` option and select `Bulb[0]` as the instance that you would like to model before clicking OK. This will open up a window containing an animated view of the Bulb statechart you created, though it won't be doing anything exciting to start with.

In order to make something happen, you'll need to trigger an event. Click the `Command Prompt` button (yellow exclaimation point) on the animation toolbar to open a prompt which will allow you to add an event to the queue. Enter the line `Bulb->GEN(toggle())` into the prompt and press enter, and you'll that `Bulb[0]->toggle()` is now present in the Event Queue window, but nothing is happening. To play the event that you added, just press the green `Go Idle` button on the animation toolbar. You'll see that the OFF state and its transition arrow to ON are highlighted in gold, and the ON state is highlighted in pink to indicate that the toggle() event you fired has caused the Bulb to enter into the ON position. You can add more than one toggle() event to the queue at a time and then press `Go Idle` repeatedly to watch the model change states.

### Figure 9. The Animated Model
![Screenshot of the the animated model](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/9-animated_chart.png)

## 7. Attaching a Test Interface

Manually controlling the model through Rhapsody's animation interface is a bit tedious, so you may prefer to attach a command line test interface with which you can control the model and output diagnostics. One way you can do this is by taking advantage of Rhapsody's support for executing C++ code when the statechart changes.

We'll now add a command line menu that can be used to flip the lightswitch without having to use the animation toolbar. Open up the Bulb statechart, and double click on the ON state. In the `Action on entry` state, fill in the following code:

	bool switched = false;
	std::string command;
	 
	while (!switched) {
	  std::cout << "========================================" << std::endl;
		display_menu();
		
		std::cout << "========================================" << std::endl;
		std::cin >> command;
	 
		if (command.compare("toggle") == 0) {
			switched = true;
		} else if (command.compare("status") == 0) {
	        std::cout << "========================================" << std::endl;
	        display_status();
		} else {
			std::cout << "Unknown command: " << command << std::endl;
		}
	}
	GEN(toggle);

Then, repeat this for the OFF state. You'll notice that this code refers to two new functions, `display_status()` and `display_menu()`. To create these global functions, right click on the LightSwitch package and choose `Add New > Function`. Set the return type of your new functions to void and choose public visibility, and then enter the following code for `display_status()` and `display_menu()` respectively.
	
	// display_menu
	// Display a menu on state transitions that enumerates possible
	// commands.
	std::cout << "Actions:\n";
	std::cout << "* toggle - flip switch\n";
	std::cout << "* status - show light status/state\n";

	// display_status
	// Indicate whether the lightbulb is currently illuminated.
	bool on = Bulb.IS_IN(ON);
	std::cout << "Lightbulb: (" << (on ? "*" : "O") << ")\n";

To see the test tool at work, rebuild your model with the `Generate/Make/Run` button and then reopen the Bulb statechart and click the `Go Idle` button. Clicking `Go Idle` will put the model into its default state, and you'll be greeted in the open terminal window with the menu you just defined. You can now enter `toggle` into the terminal window to see the Bulb turn on and off in the main Rhapsody window, and `status` to query which state the Bulb is in.

### Figure 10. Animating from the Test Tool
![Screenshot of the the test tool](https://raw.github.com/mansam/exploring-rhapsody/gh-pages/images/10-test_tool.png)
