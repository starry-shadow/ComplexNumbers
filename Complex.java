public class Complex {
    private double real;
    private double imaginary;
    // complex number formats:
    // A+Bi where B>1
    // A+i
    // A
    // Bi
    // i

    // constructors
    public Complex(double real, double imaginary){
        this.real=real;
        this.imaginary=imaginary;
    }

    // functions
    public Complex add(Complex o){
        double newReal=this.real+o.real;
        double newImaginary=this.imaginary+o.imaginary;
        return new Complex(newReal,newImaginary);
    }
    public Complex sub(Complex o){
        double newReal=this.real-o.real;
        double newImaginary= this.imaginary-o.imaginary;
        return new Complex(newReal,newImaginary);
    }
    public Complex mul(Complex o){
        double newReal=(this.real*o.real)+(this.imaginary*o.imaginary*-1);
        double newImaginary=(this.real*o.imaginary)+(this.imaginary*o.real);
        return new Complex(newReal,newImaginary);
    }
    public Complex div(Complex o){
        // o is the divisor
        // (this.real + this.imaginary) * (o.real + (o.imaginary * -1))
        double dividendReal= (this.real*o.real)+(this.imaginary*((o.imaginary*-1)*-1));
        double dividendImaginary=(this.real*(o.imaginary*-1))+(this.imaginary*(o.real));
        double divisorReal=(o.real*o.real)+(o.imaginary*(o.imaginary*-1)*-1);
        //double divisorImaginary=(o.real*(o.imaginary*-1))+(o.real*o.imaginary);
        double newReal= dividendReal/divisorReal;
        double newImaginary=dividendImaginary/divisorReal;
        return new Complex(newReal,newImaginary);
    }

    //int formal parameter
    public Complex add(double n){
        double newReal=this.real+n;
        return new Complex(newReal,this.imaginary);
    }
    public Complex sub(double n){
        double newReal=this.real-n;
        return new Complex(newReal,this.imaginary);
    }
    public Complex mul(double n){
        double newReal=this.real*n;
        double newImaginary=this.imaginary*n;
        return new Complex(newReal,newImaginary);
    }
    public Complex div(double n){
        double newReal=this.real/n;
        double newImaginary=this.imaginary/n;
        return new Complex(newReal,newImaginary);
    }
    // new toString method
    public String toString(){
        if(imaginary>0) {
            return "(" + real +"+"+imaginary+"i)";
        }
        else{
            return "(" + real +imaginary+"i)";
        }
    }
    public static void main(String[] args){
        Complex complex1=new Complex(1,2);
        Complex complex2=new Complex(1,3);
        System.out.println(complex1+" + "+complex2+" = "+complex1.add(complex2));
        System.out.println(complex1+" - "+complex2+" = "+complex1.sub(complex2));
        System.out.println(complex1+" * "+complex2+" = "+complex1.mul(complex2));
        System.out.println(complex1+" / "+complex2+" = "+complex1.div(complex2));
        //ints
        System.out.println(complex1+" + "+5+" = "+complex1.add(5));
        System.out.println(complex1+" - "+5+" = "+complex1.sub(5));
        System.out.println(complex1+" * "+5+" = "+complex1.mul(5));
        System.out.println(complex1+" / "+5+" = "+complex1.div(5));
    }
}
