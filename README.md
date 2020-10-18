# Kinect2UnityPlugin
For call from Unity3d

    CharacterSkeleton skeleton; <br>
    [DllImport("NTKINECTDLL")] private static extern System.IntPtr getKinect();<br>
    [DllImport("NTKINECTDLL")] private static extern System.IntPtr stopKinect(System.IntPtr kinect);<br>
    [DllImport("NTKINECTDLL")] private static extern int setSkeleton(System.IntPtr kinect, System.IntPtr data, System.IntPtr state, System.IntPtr id, bool video);<br>

    void Start(){ skeleton = new CharacterSkeleton(humanoid);}
    
   void Update()
    {
            float[] data = new float[bodyCount * jointCount * 3];<br>
            int[] state = new int[bodyCount * jointCount];<br>
            int[] id = new int[bodyCount];<br>
            GCHandle gch = GCHandle.Alloc(data, GCHandleType.Pinned);<br>
            GCHandle gch2 = GCHandle.Alloc(state, GCHandleType.Pinned);<br>
            GCHandle gch3 = GCHandle.Alloc(id, GCHandleType.Pinned);<br>
            int n = setSkeleton(kinect, gch.AddrOfPinnedObject(), gch2.AddrOfPinnedObject(), gch3.AddrOfPinnedObject(), showVideo);<br>
            gch.Free();
            gch2.Free();
            gch3.Free();<br>
            skeleton.set(data, state, 0, mirror, move);<br>
    }
    
