/*
	EXCEPTIONS.H

	project: Accelerator Simulator (ASim)
	website: http://www.romeovansnick.be/ASim

	main authors: Romeo Van Snick
	contributors:

    purpose:

	This file contains the exception classes that will be used troughout the project.
	Here the base exception class, as well as the derived exception classes are defined.

	The base class 'Base_Exception' is derived from the std::exception class, so that
	all of the exceptions that inherit from it can be catched as a std::exception.

	The exceptions that are defined so far are:

			- divide_by_zero
			- negative_value
			- maximum_value
			- minimum_value
			- zero_value

	All of this is wrapped in the 'ex' namespace.

	to make use of an exception just write:

			try
			{
	 		// ...
	 		throw ex::divide_by_zero(__FILE__, __LINE__);
			}
			catch ( std::exception& e)
			{
	 		std::cout << e.what() << std::endl;
	 		// ... further handling code ...
			}

	the exception can also contain an extra message (e.g. to tell the user which variable
	has gone haywire.

	 	throw ex::divide_by_zero(__FILE__, __LINE__, "optional message");

	Lastly, there is the 'ex::pad' string, which can be used for padding output in the
	catch block:

			// ...
			catch ( exception& e )
			{
	 		std::cout << e.what() << std::endl
	 		          << ex::pad  << "another sentence, aligned with the exception message"
	 		          << std::endl;
			}

 */


#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <iostream>
#include <exception>
#include <string>
#include <sstream>

namespace ex
{

	const static std::string _WARN("EXCEPTION:");
	const static std::string pad(_WARN.length()+1, ' ');

	/// the base exception class from which other exceptions are derived
	class Base_Exception : public std::exception
	{
		public:
			Base_Exception(const char* mess)
			{
				message = std::string(mess);
				std::stringstream sstr;
				sstr << _WARN  <<  " " << message;
				text = sstr.str();

			}

			Base_Exception(const char* File, int Line, const char* mess)
			{
				message = std::string(mess);

				std::stringstream sstr;
				sstr << _WARN  << " (" << File << ":" << Line <<  ") " << message;
				text = sstr.str();
			}

			Base_Exception(const char* File, int Line, const char* Info, const char* mess)
			{
				message = std::string(mess);

				std::stringstream sstr;
				sstr << _WARN << " (" << File << ":" << Line <<  ") "
				     << message << std::endl
				     << pad << Info;
				text = sstr.str();
			}

			Base_Exception(const char* Info, const char* mess)
			{
				message = std::string(mess);

				std::stringstream sstr;
				sstr << _WARN << " "
				     << message << std::endl
				     << pad << Info;
				text = sstr.str();
			}

			virtual const char* what() const throw()
			{
				return static_cast<const char*>(text.c_str());
			}

			virtual ~Base_Exception() throw() { }

		private:
			std::string text;
			std::string message;
	};

	/// when trying to divide by zero
	class divide_by_zero : public Base_Exception
	{
		public:
			divide_by_zero() : Base_Exception("trying to divide by zero"){}
			divide_by_zero(const char* Info) : Base_Exception(Info,"trying to divide by zero"){}
			divide_by_zero(const char* File, int Line) : Base_Exception(File, Line, "trying to divide by zero"){}
			divide_by_zero(const char* File, int Line, const char* Info) : Base_Exception(File, Line, Info, "trying to divide by zero"){}
	};

	/// when a value should not be negative
	class negative_value : public Base_Exception
	{
		public:
			negative_value() : Base_Exception("unexpected negative value"){}
			negative_value(const char* Info) : Base_Exception(Info,"unexpected negative value"){}
			negative_value(const char* File, int Line ) : Base_Exception(File, Line, "unexpected negative value"){}
			negative_value(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "unexpected negative value"){}
	};

	/// when a value exceeds its preset maximum
	class maximum_value : public Base_Exception
	{
		public:
			maximum_value() : Base_Exception("value exceeds maximum"){}
			maximum_value(const char* Info) : Base_Exception(Info,"value exceeds maximum"){}
			maximum_value(const char* File, int Line ) : Base_Exception(File, Line, "value exceeds maximum"){}
			maximum_value(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "value exceeds maximum"){}
	};

	/// when a value is below the preset minimum
	class minimum_value : public Base_Exception
	{
		public:
			minimum_value() : Base_Exception("value is below minimum value"){}
			minimum_value(const char* Info) : Base_Exception(Info,"value is below minimum value"){}
			minimum_value(const char* File, int Line ) : Base_Exception(File, Line, "value is below minimum value"){}
			minimum_value(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "value is below minimum value"){}
	};

	/// when a value is zero where it should not be
	class zero_value : public Base_Exception
	{
		public:
			zero_value() : Base_Exception("unexpected zero value"){}
			zero_value(const char* Info) : Base_Exception(Info,"unexpected zero value"){}
			zero_value(const char* File, int Line ) : Base_Exception(File, Line, "unexpected zero value"){}
			zero_value(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "unexpected zero value"){}
	};

	/// when a value is simply wrong
	class wrong_number : public Base_Exception
	{
		public:
			wrong_number() : Base_Exception("wrong number of command line arguments"){}
			wrong_number(const char* Info) : Base_Exception(Info,"wrong number of command line arguments"){}
			wrong_number(const char* File, int Line ) : Base_Exception(File, Line, "wrong number of command line arguments"){}
			wrong_number(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "wrong number of command line arguments"){}
	};

	/// when a value is undefined for the current setup
	class undefined_argument : public Base_Exception
	{
		public:
			undefined_argument() : Base_Exception("undefined or unknown argument"){}
			undefined_argument(const char* Info) : Base_Exception(Info,"undefined or unknown argument"){}
			undefined_argument(const char* File, int Line ) : Base_Exception(File, Line, "undefined or unknown argument"){}
			undefined_argument(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "undefined or unknown argument"){}
	};

	/// when a contianer has an unexpected length
	class invalid_length : public Base_Exception
	{
		public:
			invalid_length() : Base_Exception("invalid length of container"){}
			invalid_length(const char* Info) : Base_Exception(Info,"invalid length of container"){}
			invalid_length(const char* File, int Line ) : Base_Exception(File, Line, "invalid length of container"){}
			invalid_length(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "invalid length of container"){}
	};

	/// unknown file types
	class unknown_filetype : public Base_Exception
	{
		public:
			unknown_filetype() : Base_Exception("trying to read an unkown filetype"){}
			unknown_filetype(const char* Info) : Base_Exception(Info,"trying to read an unkown filetype"){}
			unknown_filetype(const char* File, int Line ) : Base_Exception(File, Line, "trying to read an unkown filetype"){}
			unknown_filetype(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "trying to read an unkown filetype"){}
	};

	/// unkwown object types in config file
	class wrong_type : public Base_Exception
	{
		public:
			wrong_type() : Base_Exception("trying to read an object with the wrong type"){}
			wrong_type(const char* Info) : Base_Exception(Info,"trying to make an object of the wrong type."){}
			wrong_type(const char* File, int Line ) : Base_Exception(File, Line, "trying to make an object of the wrong type."){}
			wrong_type(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "trying to make an object of the wrong type."){}
	};

	/// a file cannot be opened
	class cannot_open : public Base_Exception
	{
		public:
			cannot_open() : Base_Exception("I cannot open the file"){}
			cannot_open(const char* Info) : Base_Exception(Info,"I cannot open the file"){}
			cannot_open(const char* File, int Line ) : Base_Exception(File, Line, "I cannot open the file"){}
			cannot_open(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "I cannot open the file"){}
	};

	/// when two objects are incompatible (e.g. product of a car and a tree)
	class incompatible_objects : public Base_Exception
	{
		public:
			incompatible_objects() : Base_Exception("trying to perform an operation on incompatible objects"){}
			incompatible_objects(const char* Info) : Base_Exception(Info,"trying to perform an operation on incompatible objects"){}
			incompatible_objects(const char* File, int Line ) : Base_Exception(File, Line, "trying to perform an operation on incompatible objects"){}
			incompatible_objects(const char* File, int Line, const char* Info ) : Base_Exception(File, Line, Info, "trying to perform an operation on incompatible objects"){}
	};

} // namespace ex

#endif

/// \mainpage Accelerator Simulator
/// \section Welcome
/// Welcome to the Accelerator Simulator doxygen pages. These pages contain the description and usage
/// of all the ASim classes that are needed to simulate a particle accelerator.
///
/// \section Structure
/// The project constists out of two main parts: the Accelerator and the Visualisation
/// An Accelerator is basically a list of Poles, which can be Dipoles or Quadrupoles.
/// Accelerator takes a Beam, which is a list of Particles and propagates it trough the Poles, whilst capturing the
/// positions of the Paticles inside the Beam in a Data object.
///
/// The Data object can then be used to create 2D or 3D plots using the Plot2D or Plot3D classes. These
/// plots can be saved to file.
///
/// In the next sections will be explained what the design idea behind all the classes is.
///
/// \subsection Object
/// Most classes inherit from Object. This is a class that fixes the interface for reading something
/// from a configuration file and for generating a Tags for an object. These methods are built following
/// the <tt>Template Method Patter</tt>, so every derived class only needs to reimplement one function,
/// but inherits all of it's overloaded companions. Elements of composition are used to recursively allow
/// reading of config files (eg an Accelerator defines which Poles it will use and then asks these Poles
/// to read themselves from the config file).
///
/// \subsection Coil
/// Every type of coil inherits from the Coil base class, which defines the basic interface for
/// calculating magnetic fields etc. See RectCoil for a derived class.
///
/// \subsection Pole
/// Every type of multipole derives from the Pole class.
/// A Pole basically holds a Coil (any type of coil that derives from the Coil base class) and provides
/// methods to calculate the Poles megnetic field and parametrize it (allowing for faster magnetic field calculations
/// later on). Dipole and Quadrupole are both derived from Pole.
///
/// \subsection Particle
/// This is the class used to define particles that have certain properties, such as restmass, charge
/// position, etc. Every particle also has a pointer to the external ODEsolver object which is used to
/// move the particle in a force field. This pointer points to an external object because that way
/// one ODEsolver can service a lot of particles (but, be aware that this could lead
/// to segmentation errors if the pointer is invalidated).
///
/// \subsection ODEsolver
/// This is the base class of all solver objects that can be used to solve ordinary differential
/// equations. The main reason a base class is used is that this allows for pointer-polymorphism
/// where an object that makes use of the ODEsolver does not need to know which kind of solver
/// that is used.
///
/// \subsection Beam
/// A Beam is basically a collection of particles, that has a certain position Distribution.
/// The Beam is constructed by supplying a 'seed' of Particles. By multiplying this
/// seed, a large collection with the same particle percentages is constructed, yet reusing
/// the particle objects (so a Beam of 50 protons and 50 neurtrons will only use one proton
/// one neutron in memory if constructed correctly).
///
/// \subsection Distribution
/// To make the form of the Beam distributions totally free, the Distributiuon base class is defined.
/// A Distribution is basically a functor that allows a 3D position to be drawn from a certain distribution
/// (e.g. GaussDist for gaussian or UniformDist for uniform distributions).
///
/// \subsection Accelerator
/// All of the above are used to build an Accelerator. This class actually does the real experiment
/// and creates the Data. It takes a set of Poles that repeated in tha same fashion as a particle seed
/// in Beam to create a long tube of Poles that only uses up several Poles in memory. A Beam can be inserted
/// and it's particles can be run trough the Poles one by one, saving the positions at the required distances.
/// The return type of the experiment (which is called \c run) is a Data object.
///
/// \subsection Data
/// The experiment that is run in Accelerator returns Data. This object holds the positions of the particles
/// along the Accelerator tube and provides methods to return Paths or Sections.
///
/// \subsection Path
/// A Path is the trajectory that a Particle makes inside the Accelerator. It is saved in the \f$(\theta,x,y)\f$
/// coordinate system, meaning that the \f$x\f$ and \f$y\f$ positions inside the plane perpendicular to the
/// tubes direction are saved for each angle of measurement \f$\theta\f$.
///
/// \subsection Section
/// A Section is the collection of positions of each Particle at a certain position in the tube. The positions are
/// save in \f$(x,y)\f$ format, for each particle.
///
/// \subsection Plot2D
/// This class can be used to generate 2D plots from the Sections and Paths that are saved in Data. Several plots can be made:
/// a scatter plot of a certain Section, a distribution plot of a certain Section or a projection on the plane that is
/// perpendicular to the tube for a certain Path. The colorscheme of a plot can be changed using the ColorScheme class.
///
/// \subsection ColorScheme
/// This class holds information about the colors a Plot2D plot should have.
///
/// \subsection Plot3D
/// This class will generate 3D plots for Paths.
