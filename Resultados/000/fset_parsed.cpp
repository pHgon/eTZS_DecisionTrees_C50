if (ColetaDados::getFirstLevel()<=3) {
	termination=0;
}
else {
	if (ColetaDados::getFirstLevel()<=5) {
		termination=1;
	}
	else {
		if (ColetaDados::getFirstLevel()<=7) {
			termination=1;
		}
		else {
			termination=0;
		}
	}
}
