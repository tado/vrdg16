(
SynthDef("SCBass", {
	arg freq = 52.8;
	var bass =
		SinOsc.ar(0, (Sweep.ar(1.0, 2pi * [freq, 740]) + (pi/3)).wrap(-pi, pi), [2, 0.05]).mean.tanh *
		EnvGen.ar(Env([0, 0.5, 0.4, 0], [0, 0.2, 0.01], -5), doneAction: 2)!2;
	Out.ar(0, bass);
}).store;

SynthDef("Click", {
	arg pan = 0.0, amp = 0.25;
	var clicks =
		BPF.ar
		(
			PinkNoise.ar(),
			15000,
			0.9,
			25
		)
	* EnvGen.ar(Env.perc(0.00, 0.06), doneAction: 2).fold(-1, 1) ;
	clicks = Pan2.ar(clicks, pan);
	Out.ar(0, clicks * amp);

}).store;
)

Synth("SCBass", ["freq", 40]);
Synth("Click");