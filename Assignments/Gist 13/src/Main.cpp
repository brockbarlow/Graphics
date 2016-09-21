/*
Gist 13: answer the following questions and submit via gist by 9:30.

1. What is the difference between a directional and point light?

2. Which lighting model have you implemented?

3. What are the equations for your model?

4. Explain in detail how a diffuse calculation is made.

5. Explain in detail how information goes from an application to
the shader pipeline.

You can not use the Internet or code. You can use typed notes or 
handwritten notes. If you do not know the answer then put a valid 
reason for not understanding it and how someone could help you.
*/

/*
1) Directional Light - travels globally in a set direction. The core of Directional Light is about direction.
   Point Light - emits across a volume. The core of Point Light is about position.
*/

/*
2) I have implemented the Point Light model.
*/

/*
3) Ambient Equation (Ia * Ka * hemisphere)
   Diffuse Equation (Kd * lamberterm * Id)
   Specular Equation (Is * Ks * specularTerm)
*/

/*
4) Diffuse Equation is created by:
   taking the kd (material's reflection coefficient), mulitply it
   by the id (point light source intensity) then mulitply that by
   the lamberterm (the clamped dot product of N and Lm where N is
   the normalized vNormal and Lm is the normalized lightDirection)
*/

/*
5) Information from the application is delivered to the shader
   pipeline by buffering and binding data. 
*/