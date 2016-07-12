#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libmediainfo
PKG_VERSION:=0.7.87
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://mediaarea.net/download/source/libmediainfo/$(PKG_VERSION)
PKG_MD5SUM:=b0dcf26a7d06cba2edba0b140bdb7f1c

PKG_BUILD_DEPENDS:=libzen

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk

define Package/libmediainfo
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=Mediainfo support library
	URL:=http://mediaarea.net/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/libmediainfo/description
 libmediainfo - used by mediainfo
endef

CONFIGURE_PATH:=Project/GNU/Library

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
	(cd $(PKG_BUILD_DIR)/$(CONFIGURE_PATH); \
		DESTDIR="$(PKG_INSTALL_DIR)" make install \
	)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/include/MediaInfo $(1)/opt/include/
	$(CP) $(PKG_INSTALL_DIR)/opt/include/MediaInfoDLL $(1)/opt/include/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmediainfo.a $(1)/opt/lib/
endef

$(eval $(call BuildPackage,libmediainfo))
