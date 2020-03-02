#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=movgrab
PKG_VERSION:=3.1.2
PKG_REV:=353e9770d64082b18a15bce683b627ace2bfd81b
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/ColumPaget/Movgrab.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/movgrab
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+zlib +libopenssl
	TITLE:=movgrab is a commandline video downloader
	URL:=https://sites.google.com/site/columscode/home/movgrab
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/movgrab/description
 Movgrab is a command line tool for downloading video clips 
 from websites such as YouTube, Daily Motion, Break.com, Vimeo, Blip.tv, Liveleak and others.
endef

TARGET_CFLAGS += $(TARGET_CPPFLAGS) $(TARGET_LDFLAGS)

CONFIGURE_ARGS += \
	--prefix=/opt \
	--enable-ssl \
	--enable-largefiles

define Build/Configure
	rm -f $(PKG_BUILD_DIR)/libUseful-2.0/*.{o,a,so}
	$(call Build/Configure/Default)
endef

define Package/movgrab/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/movgrab $(1)/opt/bin
endef

$(eval $(call BuildPackage,movgrab))
