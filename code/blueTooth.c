
void
checkForUserMessage()
{
    char usrMsg[41]; //extra byte for null char

    if(userMessageAvailable())
        {
        // Get the incomming message
        readUserMessage(usrMsg);

        // The demo preceeds commands with the string "usr"
        if( usrMsg[0] == 'u' && usrMsg[1] == 's' && usrMsg[2] == 'r' )
            {
            // We have a message, see if the touch LED is found
            if(robotTouchSensor != PORTNONE)
                {
                switch( usrMsg[3] )
                  {
                  case  1:  displayString(1, "Blue  " ); break;
                  case  2:  displayString(1, "Red   " );break;
                  case  3:  displayString(1, "Green " );break;
                  case  4:  displayString(1, "Orange" );break;
                  default:  displayString(1, "      " );break;
                  }
                }
            }
        }
}


task main()
{
	eraseDisplay();
	while(true){
        checkForUserMessage();
        wait1Msec(10);
    }


}
