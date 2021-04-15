#
# Copyright (C) 2017-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=httrack
PKG_VERSION:=3.49.2
PKG_REV:=ce0f63d0b223cfbd894efd9f931aa880c22a3199
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/xroche/httrack.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=a5e7e71927ed1dbcf06314ccc28b1d4cea8f65555d3945ed1bbf252fc7f4b859

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/httrack
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libopenssl +libpthread
	TITLE:=website copier
	URL:=http://www.httrack.com
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/httrack/description
 HTTrack is a free and easy-to-use offline browser utility. It allows you
 to download a WWW site from the Internet to a local directory, building
 recursively all directories, getting HTML, images, and other files from
 the server to your computer. HTTrack arranges the original site's relative
 link-structure.
endef

CONFIGURE_ARGS += \
	--with-zlib="$(STAGING_DIR)/opt"

define Package/httrack/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/opt/bin/{htsserver,httrack,proxytrack} \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib/httrack
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/httrack/*.so* \
		$(1)/opt/lib/httrack
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* \
		$(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/share/httrack/html
	$(CP) $(PKG_INSTALL_DIR)/opt/share/httrack/{lang,templates,lang.def,lang.indexes} \
		$(1)/opt/share/httrack
	$(CP) $(PKG_INSTALL_DIR)/opt/share/doc/httrack/* \
		$(1)/opt/share/httrack/html
endef

$(eval $(call BuildPackage,httrack))
