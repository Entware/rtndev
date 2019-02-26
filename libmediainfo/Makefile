#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libmediainfo
PKG_VERSION:=18.12
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://mediaarea.net/download/source/libmediainfo/$(PKG_VERSION)
PKG_HASH:=f4e016550447f0d4443e5772e3c017d33acadc13c8e2cc3c2ed240186bac93b9

PKG_BUILD_DEPENDS:=libzen

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk

define Package/libmediainfo
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=Mediainfo support library
	URL:=http://mediaarea.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libmediainfo/description
 libmediainfo - used by mediainfo
endef

CONFIGURE_PATH:=Project/GNU/Library

CONFIGURE_ARGS += \
	--enable-static \
	--disable-shared

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
