/*
{
  "IMPORTED" : [

  ],
  "CATEGORIES" : [

  ],
  "INPUTS" : [

  ]
}
*/
float rings(vec2 p, float ring)
{
  return cos(length(p)*ring*1.5);
}

void main() {
  vec2 pos = (gl_FragCoord.xy*2.0 -RENDERSIZE) / RENDERSIZE.y;
  float px1 = cos(TIME*1.50+0.55)*0.4+pos.x;
  float py1 = sin(TIME*1.10+0.55)*0.4+pos.y;
  float px2 = cos(TIME*0.95+0.65)*0.3+pos.x;
  float py2 = sin(TIME*0.55+0.65)*0.3+pos.y;
  float px3 = cos(TIME*0.75+0.85)*0.5+pos.x;
  float py3 = sin(TIME*0.35+0.85)*0.5+pos.y;
  float colorB = rings(vec2(px1,py1),7.0)*3.0-rings(vec2(px2,py2),8.0)+2.0*rings(vec2(px3,py3),5.0);
  float colorR = rings(vec2(px1,py1),7.0)-2.0*rings(vec2(px2,py2),8.0)+1.0*rings(vec2(px3,py3),5.0);
  float colorG = rings(vec2(px1,py1),7.0)*1.5-rings(vec2(px2,py2),8.0)-2.0*rings(vec2(px3,py3),5.0);
  gl_FragColor = vec4(vec3(colorR,colorG,colorB),1.0);
}
