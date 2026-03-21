import sys
from datetime import datetime

def generate_header_file(class_name, include_private=True, include_protected=False):
    """Generate a complete C++ header file with class definition."""
    guard_name = class_name.upper() + "_HPP"
    
    # Start the class definition
    header = """#ifndef {0}
#define {0}

class {1} {{""".format(guard_name, class_name)

    # Add private section if requested
    if include_private:
        header += """
private:
    // Private member variables go here
    // Private member functions go here
"""

    # Add protected section if requested
    if include_protected:
        header += """
protected:
    // Protected member variables go here
    // Protected member functions go here
"""

    # Public section is always included (note the double curly braces for C++ code blocks)
    header += """
public:
    // Constructors
    {0}();                                  // Default constructor
    {0}(const {0}& other);         // Copy constructor
    {0}({0}&& other) noexcept;     // Move constructor
    
    // Destructor
    virtual ~{0}();
    
    // Assignment operators
    {0}& operator=(const {0}& other);    // Copy assignment
    {0}& operator=({0}&& other) noexcept; // Move assignment
    
    // Public member functions
""".format(class_name)

    # Close the class definition
    header += """
}};

#endif // {0}""".format(guard_name)
    
    return header

def generate_implementation_file(class_name):
    """Generate a basic implementation file for the class."""
    impl = """#include "{0}.hpp"

// Default constructor
{0}::{0}() {{{{
    // Initialize members here
}}}}

// Copy constructor
{0}::{0}(const {0}& other) {{{{
    // Copy members here
}}}}

// Move constructor
{0}::{0}({0}&& other) noexcept {{{{
    // Move members here
}}}}

// Destructor
{0}::~{0}() {{{{
    // Cleanup
}}}}

// Copy assignment operator
{0}& {0}::operator=(const {0}& other) {{{{
    if (this != &other) {{{{
        // Copy members here
    }}}}
    return *this;
}}}}

// Move assignment operator
{0}& {0}::operator=({0}&& other) noexcept {{{{
    if (this != &other) {{{{
        // Move members here
    }}}}
    return *this;
}}}}""".format(class_name)
    return impl

def main():
    if len(sys.argv) < 2:
        print("Usage: python script.py <ClassName> [options]")
        print("Options:")
        print("  --private    Include private section")
        print("  --protected  Include protected section")
        return
    
    class_name = sys.argv[1]
    include_private = "--private" in sys.argv
    include_protected = "--protected" in sys.argv
    
    # Generate header file
    header_content = generate_header_file(class_name, include_private, include_protected)
    with open(class_name + ".hpp", "w") as f:
        f.write(header_content)
    
    # Generate implementation file
    impl_content = generate_implementation_file(class_name)
    with open(class_name + ".cpp", "w") as f:
        f.write(impl_content)
    
    print("Generated " + class_name + ".hpp and " + class_name + ".cpp")

if __name__ == "__main__":
    main()