#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2010

include $(TOPDIR)/rules.mk

PKG_NAME:=vorbis-tools
PKG_VERSION:=1.4.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://downloads.xiph.org/releases/vorbis

include $(INCLUDE_DIR)/package.mk

define Package/vorbis-tools
    SECTION:=sound
    CATEGORY:=Sound
    TITLE:=vorbis-tools and nothing else
    URL:=http://xiph.org/vorbis/
    DEPENDS:=+libogg +libvorbis +libflac
endef

define Package/vorbis-tools/description
 oggdec, oggenc, ogginfo, vcut, vorbiscomment command line utilities
endef

CONFIGURE_ARGS+= \
    --without-flac \
    --disable-nls \

TARGET_LDFLAGS += -lm

define Package/vorbis-tools/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/oggdec/oggdec $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/oggenc/oggenc $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/ogginfo/ogginfo $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/vcut/vcut $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/vorbiscomment/vorbiscomment $(1)/opt/bin
endef

$(eval $(call BuildPackage,vorbis-tools))
