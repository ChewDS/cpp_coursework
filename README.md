#cpp_coursework
This is a library belonging to CPP coursework.

The Library Reservation System is centered on the main part of the Library Reservation module, with three main modules of Manager, Teacher, and Student attached. Combined with the functional module OrderFile, it realizes functions such as user addition and deletion, reservation and review, and storage of user and reservation records.

Library Reservation
Library Reservation is the main part of the system, and this module mainly implements the login verification function. Through the user's selection, read the corresponding stored document, compare it with the student number or work number, account number, and password entered by the user, and verify the verification code, and execute different functions according to the judgment. When all judgments are correct, enter the corresponding module and execute the functions in the corresponding module.

manager
The Manager module mainly includes four functions, adding users, displaying user information, viewing library information, and clearing all reservations. When executing the Manager module, it will automatically display the total amount of each user first, and then execute the Choose module to select the next function. When the Manager chooses to add users and succeeds, it will store the corresponding user information in the student.txt file or teacher .txt file.
 
teacher
The Teacher module mainly includes two functions, reviewing appointment records and viewing all appointment information. When executing the Teacher module, the Teacher user can choose to view the reservation information or review the reservation. When the user chooses to review the reservation and pass it, the corresponding reservation information will be stored in the order.txt file to achieve the purpose of recording.
 
Student
The Student module mainly includes four functions, apply for an appointment, view your own appointment records, view all appointment records, and cancel an appointment. When executing the Student module, the Student user can make a choice. When the Student user chooses to apply for an appointment, he will make a second choice of time and place; if the user chooses to cancel the appointment and the appointment is approved, the corresponding cleaning will be carried out, and the order. The corresponding data in txt is deleted.

OrderFile
The OrderFile module is used to process reservation information, mainly responsible for reading and updating reservation records. There are two main functions in this code: the constructor and the updateOrder() function.
The constructor OrderFile::OrderFile() is mainly used to read the reservation file and load the data in the file into the data structure in the program. This function first opens the reservation file of ORDER_FILE, and creates variables to store the data read from the file, including date, time period, student number, student name, library number and reservation status. These information are used to describe an appointment record.
The updateOrder() function is used to update the appointment record file. First check whether there is an appointment record, if not, the function returns directly. If there is an appointment record, the function uses ofstream to open the appointment file, then traverses all the appointment records, and writes them back to the file in a specific format, thus completing the update of the appointment record.

system structure
The Library Reservation System takes the main body Library_Reservation_System (the file where the main function is located) as the core, and is divided into four tool classes Student, Teacher, Manager, and OrderFile. The following is a specific analysis:
Library_Reservation_System: The file where the main function is located, which is the execution program of the system. Depending on the actual selection during execution, different tool classes can be started to perform different functions.
Student: Student tool class, a tool class designed for the user of the reservation subject object Student, including functions such as reservation, cancellation of reservation, and viewing of reservation information.
Teacher: Teacher tool class, a tool class designed for the audit subject Teacher user,
It includes functions such as reviewing appointments and viewing appointment information.
Manager: Manager tool class, a tool class designed for the Manager user of the management subject object,
It includes functions such as adding users, clearing appointment records, viewing Teacher user and Student user information, etc.
OrderFile: The OrderFile tool class exists as a record library and is one of the most important programs of the system. By accepting the instructions of the tool class, making corresponding responses, and modifying the corresponding txt files through file operations, so as to realize functions such as storing data, modifying data, and displaying data.

OrderFile() constructor
OrderFile () constructor, its main function is to read data from the reservation file and save the data to the data members of the class.
Open the order file (ORDER_FILE) first during execution. Declare variables of string type, including date (date), interval (time period), stuId (student ID), stuName (student name), roomId (library number), and status (reservation status). The data member m_Size is initialized to 0, which is used to count the number of reservation records.
Use the while loop to read data line by line from the reservation file, and each loop will create a map container (with strings as keys and strings as values). Inside the body of the loop, there is a collection of if statement blocks. The function of the if statement block is to find out the position of the colon (find(":")), and use the string before the colon as the key, and the string after the colon as the value. These key-value pairs are then inserted into the previously created map container, so it needs to be parsed. This process is performed on the date, interval, stuId, stuName, roomId and status variables, and finally makes each map container store six key-value pairs. And add this map container to the data member m_orderData (m_orderData is a nested map with integer as the key and map as the value), and increase m_Size by 1, indicating that the number of reservation records has increased by 1.
After all the appointment records in the file have been read and stored in m_orderData, close the file.
 
The addPerson() function of the Manager class
The main function of the addPerson() function of the Manager class is to add users to the system, including two types of users, Student and Teacher.
Variables are declared during execution, including fileName for the file name, tip for prompt information, errorTip for repeated input prompts, and the ofstream object ofs for file operations.
The function gets the user's input to determine the type of account to add. For example: if the input is 1, it means to add a student account. At this time, the fileName is set to STUDENT_FILE, the tip is set to "Please enter the student ID:", and the errorTip is set to "Duplicate student ID, please re-enter!".
After receiving the command, the function opens the corresponding file (Student or Teacher's file), receives the id input by the user, and calls the checkRepeat() function to check whether the id already exists. If it already exists, output an error message and ask the user to re-enter, otherwise break out of the loop. Finally add the corresponding data to the
After completing the above steps, close the open file and call the initVector() function to reinitialize the user list in the system.
Some key codes are as follows:
 
Login(string filename, int type) function of Library_Reservation_System
The Login(string filename, int type) function realizes: read the user information in the file according to the identity type, verify whether the input information is consistent with the information stored in the file, and create the corresponding object after passing the verification, and enter the corresponding submenu .
The code defines a base class pointer person to open the corresponding user information file. If the file does not exist, output a prompt and close the file, returning the function.
In the identity verification process, the identity types include student (type==1), teacher (type==2), and administrator (type==3). For each type, the code reads the corresponding information from the file, including id, name and password. Then prompt the user to enter the corresponding information. If the verification code entered by the user is incorrect, the user will be prompted to re-enter. If the verification code is correct, then compare the id, name and password entered by the user with those read in the file.
If the id, user name and password all match successfully, create the corresponding student, teacher or administrator object, and call the corresponding submenu function. If one or more of the id, username or password do not match, an error message will be prompted and the screen will be cleared to allow the user to re-enter.
At the same time, this part utilizes the characteristics of polymorphism and inheritance. In the submenu functions, there will be some common operations and some characteristic operations, which require these functions to be overloaded in their respective subclasses. In this way, we can achieve code reuse and reduce redundancy.

The experimental design of the Library Reservation System basically meets the expected goals, realizing the expected appointment, review, adding personnel, storing data, modifying files and other functions, and basically completing the purpose of in-depth understanding and application of course content. Library Reservation System is a simple and fully functional back-end system, which is similar to the existing library reservation system and conforms to the actual logic function. Of course, there are still deficiencies in this experiment, including but not limited to no graphics or linkage with the front end, the overall process and functions are not perfect, and there is still room for improvement.

Translation:
Library Reservation System以主体部分Library Reservation模块为中心，下附Manager、Teacher、Student三个主要模块，结合功能模块OrderFile，实现用户增删、预约及审核、存储用户及预约记录等功能。

Library Reservation
Library Reservation是该系统的主体部分,该模块主要实现了登录验证功能。通过用户的选择，读取相应的存储文档，与用户输入的学号或者工号、账号、密码进行对比，并进行验证码的验证，根据判断正误执行不同的功能。当所有判断无误时，进入相应的模块，执行对应模块中的功能。

Manager
Manager模块主要包含了四个功能，添加用户、显示用户信息、查看图书馆信息、清空所有预约。在执行Manager模块时，会先自动显示各用户的总量，再执行Choose模块进行下一步功能的选择，当Manager选择增加用户并成功时，会将对应的用户信息存储到student.txt文件或者teacher.txt文件中。
 
Teacher
Teacher模块主要包含了两个功能，审核预约记录和查看所有预约信息。在执行Teacher模块时，Teacher用户可以进行选择，查看预约信息或者审核预约，当用户选择审核预约并通过时，会将对应的预约信息存储到order.txt文件中，达到记录的目的。
 
Student
Student模块主要包含了四个功能，申请预约、查看自身预约记录、查看所有预约记录、取消预约。在执行Student模块时，Student用户可以进行选择当Student用户选择申请预约时，会进行时间和地点的二次选择；若用户选择取消预约并且预约审核通过时，则会进行相应的清理，将order.txt中的对应数据删除。

OrderFile
OrderFile模块用于处理预约信息，主要是负责读取和更新预约记录。这段代码中有两个主要的函数：构造函数和updateOrder()函数。
构造函数OrderFile::OrderFile()主要用于读取预约文件，并将文件中的数据加载到程序中的数据结构中。这个函数首先打开ORDER_FILE的预约文件，并创建变量用于存储从文件中读取的数据，包括日期、时间段、学生编号、学生姓名、图书馆编号和预约状态。这些信息用于描述一条预约记录。
updateOrder()函数则用于更新预约记录文件。首先检查当前是否有预约记录，如果没有，函数直接返回。如果有预约记录，函数则利用ofstream打开预约文件，然后遍历所有的预约记录，将他们按照特定的格式写回到文件中，这样就完成了预约记录的更新。

系统架构
Library Reservation System以主体Library_Reservation_System(main函数所处文件)为核心，下分四个工具类Student、Teacher、Manager、OrderFile，以下是具体分析：
Library_Reservation_System：main函数所处文件，为系统的执行程序。执行时根据实际选择的不同，可以启动不同的工具类，执行不同的功能。
Student：Student工具类，为预约主体对象Student用户设计的工具类，包含了预约、取消预约、查看预约信息等功能。
Teacher：Teacher工具类，为审核主体对象Teacher用户设计的工具类，
包含了审核预约、查看预约信息等功能。
Manager：Manager工具类，为管理主体对象Manager用户设计的工具类，
包含了增加用户、清空预约记录、查看Teacher用户和Student用户信息等功能。
OrderFile：OrderFile工具类，作为记录库而存在，是该系统的最重要程序之一。通过接受工具类的指令，做出相应的应答，通过文件操作来进行相应txt文件的修改，从而实现存储数据、修改数据、展示数据等功能。

OrderFile()构造函数
OrderFile()构造函数，其功能主要是从预约文件中读取数据并将数据保存到类的数据成员中。
执行时首先开启预约文件（ORDER_FILE）。声明字符串类型的变量，包括date（日期），interval（时间段），stuId（学生ID），stuName（学生姓名），roomId（图书馆编号），以及status（预约状态）。数据成员m_Size初始化为0，用来统计预约记录的数量。
利用while循环从预约文件中逐行读取数据，每次循环都会创建一个map容器（以字符串为键，字符串为值）。在循环体内，有一个if语句块的集合。if语句块的功能是找出冒号的位置（find(":")），并将冒号前的字符串作为key，冒号后的字符串作为value。这些键值对然后插入到前面创建的map容器中，所以需要对其进行解析。这个处理过程对date，interval，stuId，stuName，roomId和status变量都进行了，最终使每个map容器存储六个键值对。并将这个map容器添加到数据成员m_orderData中（m_orderData是一个嵌套的map，以整数为键，map为值），并将m_Size增加1，表示预约记录的数量增加了1。
当文件中所有的预约记录都被读取并存储到m_orderData后，关闭文件。
 
Manager类的addPerson()函数
Manager类的addPerson()函数的主要功能是向系统中添加用户，包括Student和Teacher两种用户类型。
执行时声明变量，包括用于文件名的fileName，提示信息的tip，重复输入提示的errorTip，以及用于文件操作的ofstream对象ofs。
函数获取用户的输入，决定添加的账户类型。例如：输入为1，表示要添加学生账户，此时fileName设置为STUDENT_FILE，tip设置为"请输入学号："，errorTip设置为"学号重复，请重新输入！"。
接收到指令之后，函数打开相应的文件（Student或Teacher的文件），接收用户输入的id，调用checkRepeat()函数检查这个id是否已经存在。如果已经存在，就输出错误提示并要求用户重新输入，否则就跳出循环。最终将相应的数据添加到
完成以上步骤之后，关闭打开的文件，并调用initVector()函数，重新初始化系统中的用户列表。
部分关键代码如下：
 
Library_Reservation_System的Login(string filename, int type)函数
Login(string filename, int type)函数实现了：根据身份类型读取文件内用户信息、验证输入的信息与文件内存储的信息是否一致，并在通过验证后创建对应的对象，进入对应的子菜单。
代码定义了一个基类指针person，打开相应的用户信息文件。如果文件不存在，则输出提示并关闭文件，返回函数。
在验证身份环节，身份类型包括学生(type==1)，老师(type==2)，和管理员(type==3)。对于每一种类型，代码从文件中读取对应的信息，包括id，姓名和密码。然后提示用户输入相应的信息，如果用户输入的验证码不正确，将提示用户重新输入。如果验证码正确，再比对用户输入的id，姓名和密码是否与文件中读取的一致。
若id、用户名和密码都匹配成功，则创建相应的学生、老师或管理员对象，并调用对应的子菜单函数。如果id、用户名或密码有一个或多个不匹配，则会提示错误信息，并清屏，让用户重新输入。
同时该部分利用了多态和继承的特性。在子菜单函数中，会有一些共性的操作，也会有一些特性的操作，这就需要在各自的子类中重载这些函数。通过这种方式，我们可以实现代码的复用和减少冗余。

Library Reservation System实验设计基本符合预期目标，实现了预期的预约、审核、添加人员、存储数据、修改文件等功能，基本完成了对课程内容深入了解与应用的目的。Library Reservation System是一款简洁的、功能较为齐全的后端System，与已有的图书馆预约系统功能相近，符合实际逻辑功能。当然，该项实验仍有不足，包括但不限于未进行图形化或者与前端联动、整体流程和功能不够完善，仍有改进的空间。
