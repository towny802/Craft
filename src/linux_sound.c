void walkSoundStart(){
    system("pkill -CONT play &");
}

void walkSoundStop(){
    system("pkill -STOP play &");
}

void walkSoundInit(){
    system("play -q ./step_sound.wav repeat 99999 &");
}