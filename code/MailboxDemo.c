
string sName[kNumbOfMailboxes];
int nMsgSize;
int nNumbOfMsg = 0;
signed char readMsg[25];

task main()
{
	for (int i = 0; i < kNumbOfMailboxes; ++i)
	{
		getMailboxName(i, sName[i], sizeof(string));
	}
	sleep(2000);

	openMailbox(0, "longName");
	getMailboxName(0, sName[10], sizeof(string));
	sleep(500);

	openMailbox(0, "short");
	getMailboxName(0, sName[10], sizeof(string));
	closeMailbox(0);
	openMailbox(0, "0");
	while (true)
	{
		nMsgSize = getMailboxMessageSize(0);
		if (nMsgSize > 0)
		{
			if (nMsgSize > sizeof(readMsg))
				nMsgSize = sizeof(readMsg);
			memset(&readMsg[0], 0xFF, sizeof(readMsg));
			readMailbox(0, &readMsg[0], nMsgSize);
			++nNumbOfMsg;

			switch( readMsg[0] )
     	{
     		case  'B':  displayString(1, "Blue  " ); break;
        case  'R':  displayString(1, "Red   " );break;
        case  'G':  displayString(1, "Green " );break;
        case  'H':  displayString(1, "Orange" );break;
        default:  displayString(1, "      " );break;
      }
		}
		sleep(10);
	}
	return;
}
