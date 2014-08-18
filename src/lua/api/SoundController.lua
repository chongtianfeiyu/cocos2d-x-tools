
--------------------------------
-- @module SoundController
-- @extend YHObject
-- @parent_module 

--------------------------------
-- @function [parent=#SoundController] stopAllEffects 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] allFiles 
-- @param self
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- @function [parent=#SoundController] fileWithKey 
-- @param self
-- @param #string str
-- @return char#char ret (return value: char)
        
--------------------------------
-- @function [parent=#SoundController] getEffectsVolume 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- @function [parent=#SoundController] fadeInVolume 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] stopEffect 
-- @param self
-- @param #unsigned int int
        
--------------------------------
-- @function [parent=#SoundController] pauseBackgroundMusic 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] willPlayBackgroundMusic 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] setBackgroundMusicVolume 
-- @param self
-- @param #float float
        
--------------------------------
-- @function [parent=#SoundController] appendMappingFile 
-- @param self
-- @param #cc.__Dictionary __dictionary
        
--------------------------------
-- @function [parent=#SoundController] playEffectWithKey 
-- @param self
-- @param #string str
-- @param #bool bool
-- @param #float float
-- @param #float float
-- @param #float float
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- @overload self         
-- @overload self, bool         
-- @function [parent=#SoundController] stopBackgroundMusic
-- @param self
-- @param #bool bool

--------------------------------
-- @function [parent=#SoundController] getBackgroundMusicVolume 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- @function [parent=#SoundController] isBackgroundMusicPlaying 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#SoundController] init 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] pauseAllEffects 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] preloadBackgroundMusic 
-- @param self
-- @param #char char
        
--------------------------------
-- @function [parent=#SoundController] playBackgroundMusic 
-- @param self
-- @param #char char
-- @param #bool bool
        
--------------------------------
-- @function [parent=#SoundController] update 
-- @param self
-- @param #float float
        
--------------------------------
-- @function [parent=#SoundController] playEffect 
-- @param self
-- @param #char char
-- @param #bool bool
-- @param #float float
-- @param #float float
-- @param #float float
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- @function [parent=#SoundController] resumeAllEffects 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] playBGMWithKey 
-- @param self
-- @param #string str
-- @param #bool bool
        
--------------------------------
-- @function [parent=#SoundController] unloadEffect 
-- @param self
-- @param #char char
-- @param #bool bool
        
--------------------------------
-- @function [parent=#SoundController] setSubPath 
-- @param self
-- @param #string str
        
--------------------------------
-- @function [parent=#SoundController] rewindBackgroundMusic 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] preloadEffect 
-- @param self
-- @param #char char
-- @param #bool bool
        
--------------------------------
-- @function [parent=#SoundController] fadeOutVolume 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] getSubPath 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- @function [parent=#SoundController] pauseEffect 
-- @param self
-- @param #unsigned int int
        
--------------------------------
-- @function [parent=#SoundController] resumeBackgroundMusic 
-- @param self
        
--------------------------------
-- @function [parent=#SoundController] setEffectsVolume 
-- @param self
-- @param #float float
        
--------------------------------
-- @function [parent=#SoundController] resumeEffect 
-- @param self
-- @param #unsigned int int
        
--------------------------------
-- @function [parent=#SoundController] sharedSoundController 
-- @param self
-- @return SoundController#SoundController ret (return value: SoundController)
        
return nil
