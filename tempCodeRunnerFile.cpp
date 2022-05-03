cout<<"| "<<findCourse -> id_Subject<<"\t\t| "<<findCourse -> name_Subject<<"\t\t| ";

                                //Teacher Name
                                if ((findCourse -> teacher_Name).size() > 14) cout<<findCourse -> teacher_Name<<"\t| ";
                                else cout<<findCourse -> teacher_Name<<"\t\t| ";
                                
                                //Start date, Endate
                                cout<<findCourse -> startDate<<"\t| "<<findCourse -> endDate<<"\t| "<<findCourse -> day_Of_Session_1<<"\t\t| ";

                                if (findCourse -> at_Time_1 == "S3" ) cout<<"13:30 - 15:29\t| ";
                                if (findCourse -> at_Time_1 == "S4" ) cout<<"15:30 - 17:29\t| ";
                                if (findCourse -> at_Time_1 == "S1" ) cout<<"7:30 - 9:29\t| ";
                                if (findCourse -> at_Time_1 == "S2" ) cout<<"9:30 - 11:29\t| ";

                                cout<<findCourse -> day_Of_Session_2<<"\t\t| ";

                                if (findCourse -> at_Time_2 == "S3" ) cout<<"13:30 - 15:29\t| ";
                                if (findCourse -> at_Time_2 == "S4" ) cout<<"15:30 - 17:29\t| ";
                                if (findCourse -> at_Time_2 == "S1" ) cout<<"7:30 - 9:29\t| ";
                                if (findCourse -> at_Time_2 == "S2" ) cout<<"9:30 - 11:29\t| ";

                                cout<<findCourse -> number_Of_Credit<<"\t\t\t| "<<findCourse -> maximumRegrister<<" \t\t|"<<endl;
