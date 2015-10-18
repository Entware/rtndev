#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=djmount
PKG_VERSION:=0.71
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)/$(PKG_NAME)/$(PKG_VERSION)
PKG_MD5SUM:=c922753e706c194bf82a8b6ca77e6a9a

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/djmount
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libupnp +libfuse $(ICONV_DEPENDS)
	TITLE:=mount MediaServers content as a Linux filesystem
	URL:=http://djmount.sourceforge.net
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/djmount/description
 djmount is a UPnP AV client. It mounts as a Linux filesystem the media content
 of compatible UPnP AV devices. Djmount discovers automatically all UPnP Media
 Servers on the network, and make the content available in a directory tree.
 All shared files (e.g. Audio or Video files) are directly visible and can be
 played using your favorite media player.
endef

CONFIGURE_ARGS += \
	--disable-debug \
	--with-libiconv-prefix=$(ICONV_PREFIX) \
	--with-external-libupnp \
	--with-libupnp-prefix=$(STAGING_DIR)/opt \

define Package/djmount/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/djmount $(1)/opt/bin/
endef

$(eval $(call BuildPackage,djmount))
