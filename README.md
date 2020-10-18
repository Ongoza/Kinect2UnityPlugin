# Kinect2UnityPlugin \n
For call from Unity3d\n

CharacterSkeleton skeleton;
    [DllImport("NTKINECTDLL")] private static extern System.IntPtr getKinect();
    [DllImport("NTKINECTDLL")] private static extern System.IntPtr stopKinect(System.IntPtr kinect);
    [DllImport("NTKINECTDLL")] private static extern int setSkeleton(System.IntPtr kinect, System.IntPtr data, System.IntPtr state, System.IntPtr id, bool video);

    void Start(){ skeleton = new CharacterSkeleton(humanoid);}
    
   void Update()
    {
            float[] data = new float[bodyCount * jointCount * 3];
            int[] state = new int[bodyCount * jointCount];
            int[] id = new int[bodyCount];
            GCHandle gch = GCHandle.Alloc(data, GCHandleType.Pinned);
            GCHandle gch2 = GCHandle.Alloc(state, GCHandleType.Pinned);
            GCHandle gch3 = GCHandle.Alloc(id, GCHandleType.Pinned);
            int n = setSkeleton(kinect, gch.AddrOfPinnedObject(), gch2.AddrOfPinnedObject(), gch3.AddrOfPinnedObject(), showVideo);
            gch.Free();
            gch2.Free();
            gch3.Free();
            skeleton.set(data, state, 0, mirror, move);
    }
    
