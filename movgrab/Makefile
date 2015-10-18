#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=movgrab
PKG_VERSION:=1.2.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://sites.google.com/site/columscode/files/
PKG_MD5SUM:=db162d6963b9753d6235f23419d08a5a

include $(INCLUDE_DIR)/package.mk

define Package/movgrab
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+zlib +libopenssl
	TITLE:=movgrab is a commandline video downloader
	URL:=https://sites.google.com/site/columscode/home/movgrab
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/movgrab/description
 Movgrab is a command line tool for downloading video clips 
 from websites such as YouTube, Daily Motion, Break.com, Vimeo, Blip.tv, Liveleak and others.
endef

TARGET_CFLAGS += $(TARGET_CPPFLAGS) $(TARGET_LDFLAGS)

CONFIGURE_ARGS += \
	--prefix=/opt \
	--enable-ssl \
	--enable-largefiles \

define Build/Configure
	rm -f $(PKG_BUILD_DIR)/libUseful-2.0/*.{o,a,so}
	$(call Build/Configure/Default)
endef

define Package/movgrab/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/movgrab $(1)/opt/bin
endef

$(eval $(call BuildPackage,movgrab))
