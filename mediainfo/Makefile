#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mediainfo
PKG_VERSION:=0.7.80
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://mediaarea.net/download/source/mediainfo/$(PKG_VERSION)
PKG_MD5SUM:=718b104084190a045262933985555fbb

PKG_BUILD_DEPENDS:=libzen libmediainfo

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk

define Package/mediainfo
	SECTION:=multimedia
	CATEGORY:=Multimedia
	TITLE:=Mediainfo
	URL:=http://mediaarea.net/
	DEPENDS:=+zlib +libstdcpp +USE_UCLIBC:libpthread
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/mediainfo/description
 MediaInfo is a convenient unified display of the most relevant technical and tag data for video and audio files
endef

CONFIGURE_PATH:=Project/GNU/CLI

define Build/Configure
	(cd $(PKG_BUILD_DIR)/$(CONFIGURE_PATH); \
		./autogen.sh; \
	)
	$(call Build/Configure/Default)
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)/$(CONFIGURE_PATH) \
		LDFLAGS="$(TARGET_CFLAGS) $(TARGET_LDFLAGS)" \
		CC="$(TARGET_CC)"
endef

define Package/mediainfo/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/$(CONFIGURE_PATH)/mediainfo $(1)/opt/bin
endef

$(eval $(call BuildPackage,mediainfo))
