#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Patches taken from https://bitbucket.org/padavan/rt-n56u project
# No any updates will be provided in future

include $(TOPDIR)/rules.mk

PKG_NAME:=firefly
PKG_REV:=1696
PKG_VERSION:=r$(PKG_REV)
PKG_RELEASE:=2

PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=http://svn.code.sf.net/p/mt-daapd/code/trunk
PKG_SOURCE:=$(PKG_SOURCE_SUBDIR).tar.gz

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/firefly
	SECTION:=sound
	CATEGORY:=Sound
	DEPENDS:=$(ICONV_DEPENDS) +libvorbis +libflac +ffmpeg +libsqlite3 +libid3tag
	TITLE:=Firefly Media Server
	URL:=http://www.fireflymediaserver.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/firefly/description
 Firefly Media Server (formerly mt-daapd) is an open-source audio media server
 for the Roku SoundBridge and iTunes. It serves media files using Roku Server
 Protocol (RSP) and Digital Audio Access Protocol (DAAP).
endef

define Package/firefly/conffiles
/opt/etc/mt-daapd.conf
endef

CONFIGURE_VARS += \
	ac_cv_func_setpgrp_void=yes \
	ac_cv_lib_FLAC_FLAC__metadata_chain_read=yes \

CONFIGURE_ARGS += \
	--enable-iconv \
	--enable-mdns \
	--enable-ffmpeg \
	--enable-flac \
	--enable-sqlite3 \
	--enable-oggvorbis \
	--with-libiconv-prefix=$(ICONV_PREFIX) \

define Build/Configure
	chmod +x $(PKG_BUILD_DIR)/configure
# This is a workaround for buggy 'patch' which can't delete text files
# with CR+LF line ends
	for file in `cat ./files/to_be_deleted.lst`; do \
		$(RM) $(PKG_BUILD_DIR)/$$$$file; \
	done
	$(call Build/Configure/Default)
endef

define Package/firefly/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/mt-daapd $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/wavstreamer $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/contrib/mt-daapd-ssc.sh $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib/mt-daapd/plugins
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/opt/lib/mt-daapd/plugins/{out-daap,rsp,ssc-ffmpeg,ssc-script}.so \
		$(1)/opt/lib/mt-daapd/plugins
	$(INSTALL_DIR) $(1)/opt/share/mt-daapd/admin-root
	$(CP) $(PKG_INSTALL_DIR)/opt/share/mt-daapd/admin-root/* $(1)/opt/share/mt-daapd/admin-root
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/contrib/mt-daapd.conf $(1)/opt/etc
	$(INSTALL_BIN) ./files/S43firefly $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/var/cache/mt-daapd $(1)/opt/var/log
endef

$(eval $(call BuildPackage,firefly))
