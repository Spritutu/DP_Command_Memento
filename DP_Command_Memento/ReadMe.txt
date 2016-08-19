================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : DP_Command_Memento Project Overview
===============================================================================

The application wizard has created this DP_Command_Memento application for
you.  This application not only demonstrates the basics of using the Microsoft
Foundation Classes but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your DP_Command_Memento application.

DP_Command_Memento.vcxproj
    This is the main project file for VC++ projects generated using an application wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    application wizard.

DP_Command_Memento.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

DP_Command_Memento.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CDP_Command_MementoApp application class.

DP_Command_Memento.cpp
    This is the main application source file that contains the application
    class CDP_Command_MementoApp.

DP_Command_Memento.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
    Visual C++. Your project resources are in 1033.

res\DP_Command_Memento.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file DP_Command_Memento.rc.

res\DP_Command_Memento.rc2
    This file contains resources that are not edited by Microsoft
    Visual C++. You should place all resources not editable by
    the resource editor in this file.


/////////////////////////////////////////////////////////////////////////////

The application wizard creates one dialog class:

DP_Command_MementoDlg.h, DP_Command_MementoDlg.cpp - the dialog
    These files contain your CDP_Command_MementoDlg class.  This class defines
    the behavior of your application's main dialog.  The dialog's template is
    in DP_Command_Memento.rc, which can be edited in Microsoft Visual C++.

/////////////////////////////////////////////////////////////////////////////

Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named DP_Command_Memento.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

DP_Command_Memento.manifest
	Application manifest files are used by Windows XP to describe an applications
	dependency on specific versions of Side-by-Side assemblies. The loader uses this
	information to load the appropriate assembly from the assembly cache or private
	from the application. The Application manifest  maybe included for redistribution
	as an external .manifest file that is installed in the same folder as the application
	executable or it may be included in the executable in the form of a resource.
/////////////////////////////////////////////////////////////////////////////

Other notes:

The application wizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, you will need
to redistribute the MFC DLLs. If your application is in a language
other than the operating system's locale, you will also have to
redistribute the corresponding localized resources mfc110XXX.DLL.
For more information on both of these topics, please see the section on
redistributing Visual C++ applications in MSDN documentation.

/////////////////////////////////////////////////////////////////////////////
